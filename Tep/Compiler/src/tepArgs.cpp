#include "../include/tepArgs.hpp"

namespace tep
{
    Args Arguments::ArgumentType(const std::string& arg) noexcept
    {
        if(arg == ("new")) return Args::NEW;
        if(arg == ("compile")) return Args::COMPILE;
        return Args::NONE;
    };
    
}

