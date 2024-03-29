#include "../../include/tepCore/CompileProcess.hpp"
#include <algorithm>

namespace tep
{
    namespace Core
    {
        CompileProcess::CompileProcess(const std::filesystem::path& filePath)
        : m_filePath(filePath)
        {
            if(!std::filesystem::exists(m_filePath))
            {
                Log("[Error] : File path not exist");
                return;
            }
        };
        CompileProcess::CompileProcess(const std::string& filePath)
        {

        };
        void CompileProcess::Run()
        {
            //tep::IO::DirectoryOperations::CreateFile(m_filePath);
            std::ifstream file(m_filePath , std::ios_base::out);
            std::ofstream extFile("out_file.cpp" , std::ios_base::out);

            ProcessTimer pTimer;
            pTimer.Start();
            Log(pTimer.getStart(), attribute::__DEBUG , "Compilation started.");
            
            if(file.is_open())
            {
                ProcessProperties* processProp = new ProcessProperties();
                std::shared_ptr<LayoutEvents> layoutEvents = std::make_shared<LayoutEvents>();
                //TODO: load extension --

                layoutEvents->setProcessProp(processProp);

                layoutEvents->InitAll();
                
                std::int64_t braceCounter = 0;
                std::vector<std::string> lineStorage;

                ProcessEvent preProcess = ProcessEvent();
                ProcessEvent contentProcess = ProcessEvent();
                ProcessEvent postProcess = ProcessEvent();

                const std::regex layoutMatch("\\s*\\S+\\s*\\]",std::regex_constants::ECMAScript);
                const std::regex nonspaceMatch("[^\\s].+");
                
                auto layoutOperative = [&](std::string rawIdentifier){
                    auto identifierBegin = std::find_if(rawIdentifier.begin(), rawIdentifier.end(), [](unsigned char c){ return !std::isspace(c);});
                    
                    std::string identifier;
                    std::copy(identifierBegin, rawIdentifier.end(), std::back_inserter(identifier));

                    for(const auto& n : layoutEvents->events)
                    {
                        if(n.first == identifier){
                            return n.first;
                        }
                    }
                    return std::string("");
                };
                std::string lt; // line temp
                while(!file.eof())
                {
                    std::getline(file , lt , '\n');
                    lineStorage.push_back(lt);
                }
                for(const auto& currentLine : lineStorage)
                {
                    processProp->lineStream = currentLine;
                    processProp->outStream.clear();
                    processProp->line++;

                    const std::size_t layoutBracePos = currentLine.find(']');
                    std::string layoutIdentifier = currentLine.substr(0, layoutBracePos+1);
                    std::smatch layoutMatches;

                    //tep::Log("LI: " + layoutIdentifier);

                    if(std::regex_search(layoutIdentifier , layoutMatches , layoutMatch))
                    {
                        std::ssub_match match = layoutMatches[0];
                        const std::string rawLayoutIdentifier = match.str().substr(0 , match.str().length()-1);
                        const std::string operative = layoutOperative(rawLayoutIdentifier);
                        //tep::Log("OP: " + operative);
                        if(!operative.empty())
                        {
                            //Log("is matched operative");
                            const std::string op = operative.length() > 1 ? operative.substr(0,operative.length()-1) : operative;
                            if(layoutEvents->events.find(op) != layoutEvents->events.end())
                            {
                                auto currentOperation = &layoutEvents->events[op];
                                
                                if(currentOperation->ExistPreProcess())
                                    preProcess.set(currentOperation->GetPreProcess()->get());

                                if(currentOperation->ExistContentProcess())
                                    contentProcess.set(currentOperation->GetContentProcess()->get());

                                if(currentOperation->ExistPostProcess())
                                    postProcess.set(currentOperation->GetPostProcess()->get());
                            }
                        
                        }
                    }

                    if(preProcess.exist()) preProcess.call();

                    layoutEvents->setDefaultEvent([currentLine,nonspaceMatch,&processProp](){
                        processProp->outStream.replace(0,processProp->layout,processProp->layout,'\t');
                        const std::string temp = currentLine.substr(currentLine.find(']')+1 , currentLine.length()-1);
                        std::smatch matcher;
                        if(std::regex_search(temp , matcher , nonspaceMatch))
                        {
                            std::ssub_match match = matcher[0];
                            processProp->outStream.append(match.str());
                        }
                    });

                    layoutEvents->setExtEvent([&extFile , &processProp](){
                        extFile << processProp->outStream << '\n';
                    });

                    if(extFile.is_open() && extFile.good())
                    {
                        if(contentProcess.exist()) contentProcess.call();
                        extFile << processProp->outStream;
                        processProp->outStream.clear();
                        if(postProcess.exist()) postProcess.call();
                    }

                    preProcess.clear();
                    contentProcess.clear();
                    postProcess.clear();
                }
                file.close();
            }
            extFile.close();

            pTimer.End();
            Log(pTimer.getEnd(), attribute::__DEBUG , "Compilation finished.");
            std::stringstream ss;
            ss << std::setprecision(4);
            ss << pTimer.getDuration().count() << " s";
            Log(std::chrono::system_clock::now(), attribute::__DEBUG , "Elapsed time : " + ss.str());
        }
    }
}