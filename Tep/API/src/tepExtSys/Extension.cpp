#include "../../include/tepExtSys/Extension.hpp"

namespace tep
{
    namespace ExtSys
    {
        Extension::Extension(const std::string& tag , const std::string& name)
        : m_tag(tag) , m_name(name)
        {
        }
    }
}