#ifndef TEP_IO
#define TEP_IO
#define TEPIMPL(funcName) tep##funcName
#include <filesystem>
#include <fstream>
#include "tepAssert.hpp"
namespace tep
{
    namespace IO
    {
        class DirectoryOperations
        {
            public:
                static void TEPIMPL(CreateProject)(const std::filesystem::path& folderPath , const std::string& projectName);
                static void TEPIMPL(CreateProject)(const std::string& folderPath , const std::string& projectName);
                static void TEPIMPL(CreateFile)(const std::filesystem::path& filePath , const std::string& fileName , const std::string& extension);
                static void TEPIMPL(CreateFile)(const std::filesystem::path& filePath , const std::string& fileName);
                static void TEPIMPL(CreateFile)(const std::string& filePath , const std::string& fileName);
                static void TEPIMPL(CreateFile)();
                static inline const std::string n_project_source = "Source";
                static inline const std::string n_project_include = "Include";
                static inline const std::string n_project_teph = "Header";
        };
        class CompileProcess
        {
            public:
                CompileProcess(const std::filesystem::path& filePath);
                CompileProcess(const std::string& filePath);
            private:
                std::filesystem::path m_filePath;
        };
        class CompileConfig
        {

        };
    };
};
#endif
