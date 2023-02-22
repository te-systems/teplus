#include "../../include/tepCore/ProcessTimer.hpp"

namespace tep
{
    namespace Core
    {
        void ProcessTimer::Start() noexcept
        {
            start = std::chrono::system_clock::now();
        }
        
        void ProcessTimer::End() noexcept
        {
            end = std::chrono::system_clock::now();
        }
        
        void ProcessTimer::Clear() noexcept
        {
            start = std::chrono::system_clock::time_point();
            end = std::chrono::system_clock::time_point();
        }
        const std::chrono::system_clock::time_point ProcessTimer::getStart() const
        {
            return start;
        }
        const std::chrono::system_clock::time_point ProcessTimer::getEnd() const
        {
            return end;
        }

        const std::chrono::duration<float> ProcessTimer::getDuration() const
        {
            return std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
        }
        const std::string ProcessTimer::getFormattedTimePoint(std::chrono::system_clock::time_point timePoint)
        {
            const time_t time = std::chrono::system_clock::to_time_t(timePoint);
            std::stringstream result;
            result << std::put_time(std::localtime(&time) , "%Y-%m-%d %H:%M:%S");
            return result.str();
        }
    }
}