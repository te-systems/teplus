#include "../../include/tepCore/LayoutEvents.hpp"

namespace tep
{
    namespace Core
    {
        LayoutEvents::LayoutEvents()
        {
            m_defaultEvent = [](){};
            m_extEvent = [](){};
        }
        
        void LayoutEvents::InitAll() noexcept
        {
            events.insert(
                std::pair<std::string , LayoutOperation>(
                    "o",
                    LayoutOperation(
                        ProcessEvent([&](){}),
                        ProcessEvent([&](){
                            m_defaultEvent();
                        }),
                        ProcessEvent([&](){
                            m_extEvent();
                        })
                    )
                )
            );
            events.insert(
                std::pair<std::string , LayoutOperation>(
                    "+",
                    LayoutOperation(
                        ProcessEvent([&](){}),
                        ProcessEvent([&](){
                            m_defaultEvent();
                        }),
                        ProcessEvent([&](){
                            processProp->layout++;
                            processProp->outStream.append("{");
                            m_extEvent();
                        })
                    )
                )
            );
            events.insert(
                std::pair<std::string , LayoutOperation>(
                    "-",
                    LayoutOperation(
                        ProcessEvent([&](){}),
                        ProcessEvent([&](){
                            m_defaultEvent();
                        }),
                        ProcessEvent([&](){
                            if(processProp->layout > 0){
                                processProp->layout--;
                                processProp->outStream.append("\n");
                                std::string tab(processProp->layout,'\t');
                                processProp->outStream.append(tab + "}");
                                m_extEvent();
                            }
                        })
                    )
                )
            );
            events.insert(
                std::pair<std::string , LayoutOperation>(
                    "#",
                    LayoutOperation(
                        ProcessEvent([&](){
                            processProp->outStream.append("#");
                        }),
                        ProcessEvent([&](){
                            m_defaultEvent();
                        }),
                        ProcessEvent([&](){
                            m_extEvent();
                        })
                    )
                )
            );
            events.insert(
                std::pair<std::string , LayoutOperation>(
                    ">",
                    LayoutOperation(
                        ProcessEvent([&](){
                            LayoutCommand::Execute(processProp->lineStream);
                        }),
                        ProcessEvent([&](){}),
                        ProcessEvent([&](){})
                    )
                )
            );
        }

        /*std::map<std::string , std::pair<LayoutEvents::ProcessOrder, std::function<void()>>> events {
                    {"+" ,{LayoutEvents::ProcessOrder::after, [&]()
                        {
                            processProp->layout++;
                            processProp->outStream.append("{");
                        }
                    }},
                    {"-" ,{LayoutEvents::ProcessOrder::after, [&]()
                        {
                            if(processProp->layout > 0){
                                processProp->layout--;
                                processProp->outStream.append("\n");
                                std::string tab(processProp->layout,'\t');
                                processProp->outStream.append(tab + "}");
                            }

                        }
                    }},
                    {"o" ,{LayoutEvents::ProcessOrder::before, [&](){}}},
                    {"#" ,{LayoutEvents::ProcessOrder::before, [&](){processProp->outStream.append("#");}}},
                    {">" ,{LayoutEvents::ProcessOrder::before, [&](){
                        //Log(processProp->lineStream);
                        LayoutCommand::Execute(processProp->lineStream);
                    }}},
                };*/

    }
}