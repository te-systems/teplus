#include <filesystem>
#include <chrono>
#include <algorithm>
#include <regex>
#include <functional>
#include "tepAssert.hpp"
#include "tepIO.hpp"
#include "tepLiterals.hpp"

#ifndef TEP_CORE_PROCESSTIMER
#define TEP_CORE_PROCESSTIMER

namespace tep
{
    namespace Core
    {
        class ProcessTimer
        {
            public:
                void Start() noexcept;
                void End() noexcept;
                void Clear() noexcept;
                const std::chrono::system_clock::time_point getStart() const;
                const std::chrono::system_clock::time_point getEnd() const;
                const std::chrono::duration<float> getDuration() const;
                static const std::string getFormattedTimePoint(std::chrono::system_clock::time_point timePoint);
                
            private:
                std::chrono::system_clock::time_point start;
                std::chrono::system_clock::time_point end;
                
        };
    }
}

#endif