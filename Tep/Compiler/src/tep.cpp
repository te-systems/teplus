#include "../../API/include/tepCore.hpp"
#include "../../API/include/tepIO.hpp"
#include "../include/tepArgs.hpp"
#include "../include/tepAssert.hpp"
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/format.hpp>

/*
    [Tests]

    $ tep new [<args>]
    $ tep compile [<args>]
*/

namespace cli_options = boost::program_options;
using cli_options_desc = cli_options::options_description;

int main(int argc , const char *const *argv)
{
    const std::filesystem::path path("./Tests/Project/Source/main.tep");

    cli_options_desc root("root");
    cli_options_desc generalOptions("general options");
    cli_options_desc root_generic_commands("generic options");
    cli_options_desc root_new("\"new\" Commands:");
    cli_options_desc root_compile("\"compile\" Commands:");
    cli_options_desc root_migrate("\"migrate\" Commands:");

    generalOptions.add_options()
        ("help" , "Display list of commands")
        ("new" , "Display new subcommands")
        ("compile" , "Display compile subcommands")
        ("migrate" , "Display migrate subcommands")
    ;
    root_generic_commands.add_options()
        ("path,P" , cli_options::value<std::string>() ,"Path")
        ("name,N" , cli_options::value<std::string>() ,"Name")
    ;
    root_new.add_options()
        ("project" , "new project [name] [path]")
        ("file" , "new file [--ext-tag] [name] [path]")
        
    ;
    root_compile.add_options()
    ;
    root
        .add(generalOptions)
        .add(root_generic_commands)
        .add(root_new)
        .add(root_compile)
    ;
    boost::program_options::variables_map varMap;
    boost::program_options::store(boost::program_options::parse_command_line(argc , argv, root) , varMap);
    try
    {
        boost::program_options::notify(varMap);
    }
    catch(std::exception& e)
    {
        tep::Log(e.what());
    }


    if(varMap.count("help"))
    {
        std::stringstream ss;
        if(varMap.count("new"))             ss << root_new;
        else if(varMap.count("compile"))    ss << root_compile;
        else if(varMap.count("migrate"))    ss << root_migrate;
        else                                ss << generalOptions;
        tep::Log(ss.str());
    }

    if(varMap.count("new"))
    {
        if(varMap.count("project"))
        {
            std::string path = "./Tests";
            std::string name = "SampleProject";
            if(varMap.count("path")) path = varMap["path"].as<std::string>();
            if(varMap.count("name")) name = varMap["name"].as<std::string>();
            tep::IO::DirectoryOperations::TEPIMPL(CreateProject)(path , name);
        }
        if(varMap.count("file"))
        {
            std::string path = "./Tests";
            std::string name = "main";
            if(varMap.count("path")) path = varMap["path"].as<std::string>();
            if(varMap.count("name")) name = varMap["name"].as<std::string>();
            tep::IO::DirectoryOperations::TEPIMPL(CreateFile)(path , name);
        }
    }

    if(varMap.count("compile"))
    {
        if(varMap.count("path"))
        {
            std::string current_path_str = "./Tests/Project/Source/example.tep";
            current_path_str = varMap["path"].as<std::string>();
            const std::filesystem::path current_path(current_path_str);
            tep::Core::CompileProcess m_process(current_path);
            m_process.Run();
            system("mingw32-make compile_out");
        }
    }

    return 0;
}