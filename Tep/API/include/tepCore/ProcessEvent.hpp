#include <filesystem>
#include <chrono>
#include <algorithm>
#include <regex>
#include <functional>
#include "tepAssert.hpp"
#include "tepIO.hpp"
#include "tepLiterals.hpp"

#ifndef TEP_CORE_PROCESSEVENT
#define TEP_CORE_PROCESSEVENT

namespace tep
{
    namespace Core
    {
        class ProcessEvent
        {
            public:
                ProcessEvent();
                ProcessEvent(const std::function<void()>& f);
                ProcessEvent(const ProcessEvent& other);
                ~ProcessEvent();

                const std::function<void()> get() const;
                void set(const std::function<void()>& proc) noexcept;
                void set(const ProcessEvent& other) noexcept;
                void call();
                bool exist() noexcept;
                void clear();

            private:
                std::unique_ptr<std::function<void()>> m_processEvent;

        };
    }
}

#endif