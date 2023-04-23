#ifndef TEP_CORE_LAYOUTEVENTS
#define TEP_CORE_LAYOUTEVENTS

#include <functional>
#include <string>

#include "tepAssert.hpp"

#include "LayoutOperation.hpp"
#include "ProcessEvent.hpp"
#include "LayoutCommand.hpp"
#include "ProcessProperties.hpp"

namespace tep
{
    namespace Core
    {
        class LayoutEvents
        {
            public:
                LayoutEvents();
                ~LayoutEvents();
                virtual void InitAll();
                
                std::map<const std::string , LayoutOperation> events;
                
                /*
                    * defaults
                    * TODO: Make as static literal properties
                */

               const std::function<void()> getDefaultEvent() const;
               void setDefaultEvent(const std::function<void()>& defaultEvent);

               const std::function<void()> getExtEvent() const;
               void setExtEvent(const std::function<void()>& extEvent);

                ProcessProperties* getProcessProp() const;
                void setProcessProp(ProcessProperties* processProp);
                
            private:
                ProcessProperties* m_processProp;
                std::function<void()> m_defaultEvent;
                std::function<void()> m_extEvent;
        };
    }
}

#endif