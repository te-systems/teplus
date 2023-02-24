#ifndef TEP_EXTSYS_EXTENSION
#define TEP_EXTSYS_EXTENSION

#include <string>

namespace tep
{
    namespace ExtSys
    {
        class Extension
        {
            public:
                Extension(const std::string& tag , const std::string& name);
                const std::string GetName() const;
                const std::string GetTag() const;
            private:
                std::string m_tag;
                std::string m_name;
        };
    }
}

#endif