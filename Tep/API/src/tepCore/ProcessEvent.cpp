#include "../../include/tepCore/ProcessEvent.hpp"

namespace tep
{
    namespace Core
    {
        ProcessEvent::ProcessEvent()
        {
            m_processEvent = std::make_unique<std::function<void()>>([](){});
        }

        ProcessEvent::ProcessEvent(const std::function<void()>& f)
        {
            m_processEvent = std::make_unique<std::function<void()>>(f);
        }

        ProcessEvent::ProcessEvent(const ProcessEvent& other)
        {
            m_processEvent = std::make_unique<std::function<void()>>(other.get());
        }

        ProcessEvent::~ProcessEvent()
        {
            //m_processEvent.reset();
        }

        const std::function<void()> ProcessEvent::get() const
        {
            return *m_processEvent;
        }

        void ProcessEvent::set(const std::function<void()>& proc) noexcept
        {
            *m_processEvent = proc;
        }
        
        void ProcessEvent::set(const ProcessEvent& other) noexcept
        {
            *m_processEvent = (*other.m_processEvent);
        }

        void ProcessEvent::call()
        {
            try{
                (*m_processEvent)();
            }catch(std::bad_function_call& e)
            {
                Log(e.what());
            }
        }

        bool ProcessEvent::exist() noexcept
        {
            return (bool)*m_processEvent;
        }

        void ProcessEvent::clear()
        {
            *m_processEvent = nullptr;
        }
    }
}