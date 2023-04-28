#include "../../include/tepCore/LayoutOperation.hpp"

namespace tep
{
    namespace Core
    {
        LayoutOperation::LayoutOperation()
        {

        }

        LayoutOperation::LayoutOperation(
            ProcessEvent pre,
            ProcessEvent content,
            ProcessEvent post
        )
        {
            m_preProcess = std::make_unique<ProcessEvent>(pre);
            m_contentProcess = std::make_unique<ProcessEvent>(content);
            m_postProcess = std::make_unique<ProcessEvent>(post);
        }
        LayoutOperation::LayoutOperation(const LayoutOperation& other)
        {
            this->m_preProcess = std::make_unique<ProcessEvent>(*other.GetPreProcess());
            this->m_contentProcess = std::make_unique<ProcessEvent>(*other.GetContentProcess());
            this->m_postProcess = std::make_unique<ProcessEvent>(*other.GetPostProcess());
        }

        ProcessEvent* LayoutOperation::GetPreProcess() const
        {
            return m_preProcess.get();
        }
        ProcessEvent* LayoutOperation::GetContentProcess() const
        {
            return m_contentProcess.get();
        }
        ProcessEvent* LayoutOperation::GetPostProcess() const
        {
            return m_postProcess.get();
        }
        const bool LayoutOperation::ExistPreProcess() const noexcept
        {
            return (bool)m_preProcess;
        }
        const bool LayoutOperation::ExistContentProcess() const noexcept
        {
            return (bool)m_contentProcess;
        }
        const bool LayoutOperation::ExistPostProcess() const noexcept
        {
            return (bool)m_postProcess;
        }
        void LayoutOperation::SetPreProcess(const ProcessEvent& process) noexcept
        {
            m_preProcess = std::make_unique<ProcessEvent>(process);
        }
        void LayoutOperation::SetContentProcess(const ProcessEvent& process) noexcept
        {
            m_preProcess = std::make_unique<ProcessEvent>(process);
        }
        void LayoutOperation::SetPostProcess(const ProcessEvent& process) noexcept
        {
            m_preProcess = std::make_unique<ProcessEvent>(process);
        }
    }
}