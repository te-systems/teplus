#include <filesystem>
#include <chrono>
#include <algorithm>
#include <regex>
#include <functional>
#include "tepAssert.hpp"
#include "tepIO.hpp"
#include "tepLiterals.hpp"

#ifndef TEP_CORE_PROCESSPROPERTIES
#define TEP_CORE_PROCESSPROPERTIES

namespace tep
{
    namespace Core
    {
        class ProcessProperties
        {
            public:
                ProcessProperties();
                std::size_t line;
                std::size_t layout;
                std::string lineStream;
                std::string outStream;
        };
    }
}

#endif