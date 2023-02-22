#include "../include/tepIO.hpp"

namespace tep
{
    namespace IO
    {
        void DirectoryOperations::TEPIMPL(CreateProject)(const std::filesystem::path& folderPath , const std::string& projectName)
        {
            if(!std::filesystem::exists(folderPath))
            {
                Log("[Error] : Folder path not exist.");
                return;
            }
            std::filesystem::create_directory(folderPath/projectName);
            std::filesystem::create_directory(folderPath/projectName/n_project_include);
            std::filesystem::create_directory(folderPath/projectName/n_project_source);
            std::filesystem::create_directory(folderPath/projectName/n_project_teph);
            std::ofstream main(folderPath/projectName/n_project_source/"main.tep");
            main << "+] int main()\n-] return 0;";
            main.close();
        }
        void DirectoryOperations::TEPIMPL(CreateProject)(const std::string& folderPath , const std::string& projectName)
        {
            TEPIMPL(CreateProject)(std::filesystem::path(folderPath) , projectName);
        }
        void DirectoryOperations::TEPIMPL(CreateFile)(const std::filesystem::path& filePath , const std::string& fileName , const std::string& extension)
        {
            std::ofstream file(filePath/(fileName+extension), std::ios_base::out);
            file.close();
        }
        void DirectoryOperations::TEPIMPL(CreateFile)(const std::string& filePath , const std::string& fileName)
        {
            TEPIMPL(CreateFile)(std::filesystem::path(filePath) , fileName , ".tep");
        }
        void DirectoryOperations::TEPIMPL(CreateFile)()
        {
            std::filesystem::path _path("./");
            Log("[Log] : Folder path" + _path.root_directory().string());
            return;
        }
    };
};