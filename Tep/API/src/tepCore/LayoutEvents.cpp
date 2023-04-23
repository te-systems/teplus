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

        LayoutEvents::~LayoutEvents()
        {
            delete m_processProp;
        }
        
        void LayoutEvents::InitAll()
        {
            events.insert(
                std::pair<const std::string , LayoutOperation>(
                    "o",
                    LayoutOperation(
                        ProcessEvent([&](){}),
                        ProcessEvent([&](){
                            this->getDefaultEvent();
                        }),
                        ProcessEvent([&](){
                            this->getExtEvent();
                        })
                    )
                )
            );
            events.insert(
                std::pair<const std::string , LayoutOperation>(
                    "+",
                    LayoutOperation(
                        ProcessEvent([&](){}),
                        ProcessEvent([&](){
                            this->getDefaultEvent();
                        }),
                        ProcessEvent([&](){
                            this->getProcessProp()->layout++;
                            this->getProcessProp()->outStream.append("{");
                            m_extEvent();
                        })
                    )
                )
            );
            events.insert(
                std::pair<const std::string , LayoutOperation>(
                    "-",
                    LayoutOperation(
                        ProcessEvent([&](){}),
                        ProcessEvent([&](){
                            this->getDefaultEvent();
                        }),
                        ProcessEvent([&](){
                            if(this->getProcessProp()->layout > 0){
                                this->getProcessProp()->layout--;
                                this->getProcessProp()->outStream.append("\n");
                                std::string tab(this->getProcessProp()->layout,'\t');
                                this->getProcessProp()->outStream.append(tab + "}");
                                this->getExtEvent()();
                            }
                        })
                    )
                )
            );
            events.insert(
                std::pair<const std::string , LayoutOperation>(
                    "#",
                    LayoutOperation(
                        ProcessEvent([&](){
                            this->getProcessProp()->outStream.append("#");
                        }),
                        ProcessEvent([&](){
                            this->getDefaultEvent();
                        }),
                        ProcessEvent([&](){
                            this->getExtEvent();
                        })
                    )
                )
            );
            events.insert(
                std::pair<const std::string , LayoutOperation>(
                    ">",
                    LayoutOperation(
                        ProcessEvent([&](){
                            LayoutCommand::Execute(this->getProcessProp()->lineStream);
                        }),
                        ProcessEvent([&](){}),
                        ProcessEvent([&](){})
                    )
                )
            );
        }

        const std::function<void()> LayoutEvents::getDefaultEvent() const
        {
            return m_defaultEvent;
        }
        void LayoutEvents::setDefaultEvent(const std::function<void()>& defaultEvent)
        {
            m_defaultEvent = defaultEvent;
        }

        const std::function<void()> LayoutEvents::getExtEvent() const
        {
            return m_extEvent;
        }
        void LayoutEvents::setExtEvent(const std::function<void()>& extEvent)
        {
            m_extEvent = extEvent;
        }

        ProcessProperties* LayoutEvents::getProcessProp() const
        {
            return m_processProp;
        }
        void LayoutEvents::setProcessProp(ProcessProperties* processProp)
        {
            if(m_processProp != nullptr) delete m_processProp;

            m_processProp = processProp;
        }
    }
}