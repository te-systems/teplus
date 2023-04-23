#include <filesystem>
#include <chrono>
#include <algorithm>
#include <regex>
#include <functional>

#include "tepAssert.hpp"
#include "tepIO.hpp"
#include "tepLiterals.hpp"

#include "ProcessProperties.hpp"
#include "LayoutEvents.hpp"
#include "ProcessTimer.hpp"

#ifndef TEP_CORE_COMPILEPROCESS
#define TEP_CORE_COMPILEPROCESS

namespace tep
{
    namespace Core
    {
        class CompileProcess
        {
            public:
                CompileProcess() = default;
                CompileProcess(const std::filesystem::path& filePath);
                CompileProcess(const std::string& filePath);
                void Run();
            private:
                std::filesystem::path m_filePath;
        };
    }
}

#endif