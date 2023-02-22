#include "../../include/tepCore/LayoutCommand.hpp"

namespace tep
{
    namespace Core
    {
        void LayoutCommand::Execute(const std::string& command) noexcept
        {
            std::stringstream ss;
            std::vector<std::string> arguments;
            /*ss << command;
            for(std::string arg ; ss >> arg ;)
                arguments.push_back(arg);
            for(std::size_t i = 1 ; i < arguments.size() ; i++)
            {
                Log(arguments[i]);
            }
            */

        }
    }
}