#include <filesystem>
#include <chrono>
#include <algorithm>
#include <regex>
#include <functional>
#include "tepAssert.hpp"
#include "tepIO.hpp"
#include "tepLiterals.hpp"

#include "ProcessEvent.hpp"

#ifndef TEP_CORE_LAYOUTOPERATION
#define TEP_CORE_LAYOUTOPERATION

namespace tep
{
    namespace Core
    {
        class LayoutOperation
        {
            public:
                LayoutOperation();
                LayoutOperation(
                    ProcessEvent pre,
                    ProcessEvent content,
                    ProcessEvent post
                );
                
                ProcessEvent* GetPreProcess() const;
                ProcessEvent* GetContentProcess() const;
                ProcessEvent* GetPostProcess() const;
                const bool ExistPreProcess() const noexcept;
                const bool ExistContentProcess() const noexcept;
                const bool ExistPostProcess() const noexcept;
                void SetPreProcess(const ProcessEvent& process) noexcept;
                void SetContentProcess(const ProcessEvent& process) noexcept;
                void SetPostProcess(const ProcessEvent& process) noexcept;
            private:
                std::unique_ptr<ProcessEvent> m_preProcess;
                std::unique_ptr<ProcessEvent> m_contentProcess;
                std::unique_ptr<ProcessEvent> m_postProcess;

        };
    }
}

#endif