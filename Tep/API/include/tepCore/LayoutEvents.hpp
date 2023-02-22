#include <filesystem>
#include <chrono>
#include <algorithm>
#include <regex>
#include <functional>
#include "tepAssert.hpp"
#include "tepIO.hpp"
#include "tepLiterals.hpp"

#include "LayoutOperation.hpp"
#include "ProcessEvent.hpp"
#include "LayoutCommand.hpp"
#include "ProcessProperties.hpp"

#ifndef TEP_CORE_LAYOUTEVENTS
#define TEP_CORE_LAYOUTEVENTS

namespace tep
{
    namespace Core
    {
        class LayoutEvents
        {
            public:
                LayoutEvents();
                enum ProcessOrder
                {
                    before,
                    after,
                };
                
                ProcessProperties* processProp;

                std::map<std::string , LayoutOperation> events;

                virtual void InitAll() noexcept;
                std::function<void()> m_defaultEvent;
                std::function<void()> m_extEvent;
            
        };
    }
}

#endif