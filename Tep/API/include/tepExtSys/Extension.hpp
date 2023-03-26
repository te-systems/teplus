#ifndef TEP_EXTSYS_EXTENSION
#define TEP_EXTSYS_EXTENSION

#include <filesystem>

#ifdef _WIN32
    #define TEP_EXT_API __declspec(dllexport)
#else
    #define TEP_EXT_API __declspec(dllimport)
#endif


#include <string>

namespace tep
{
    namespace ExtSys
    {
        class TEP_EXT_API Extension
        {
            public:
                Extension(const std::string& tag , const std::string& name , const std::filesystem::path& path = "./");
                const std::string GetName() const;
                const std::string GetTag() const;
            private:
                std::string m_tag;
                std::string m_name;
                std::filesystem::path m_path;
        };
    }
}

#endif