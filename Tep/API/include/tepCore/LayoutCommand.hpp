#include <filesystem>
#include <chrono>
#include <algorithm>
#include <regex>
#include <functional>
#include "tepAssert.hpp"
#include "tepIO.hpp"
#include "tepLiterals.hpp"

#ifndef TEP_CORE_LAYOUTCOMMAND
#define TEP_CORE_LAYOUTCOMMAND

namespace tep
{
    namespace Core
    {
        class LayoutCommand
        {
            public:
                static void Execute(const std::string& command) noexcept;
        };
    }
}

#endif