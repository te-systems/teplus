#ifndef TEP_ARGS
#define TEP_ARGS

#include <iostream>
#include <map>
#include <functional>
/*
- Create Project
		> tep new --project

		> tep new --file
			> [none] : main.tep
			> "file_name.extension"
			> --tepsource / --teps "name"
			> --tepheader / --teph "name"
			>> [none]
			>> [location]

	- Build Project

		> tep compile [filename] 
			> [none] -> tep
			> --header / --h "filename"
			> --source / --s "filename"
			> --manager / --m "filename"

		> tep sfcompile [filename]		
*/

namespace tep
{
    enum Args
    {
        NONE = 0,
        NEW = 1,
        COMPILE = 2,
    };

    template<typename T_ArgValue = std::function<void()>>
    class ArgNode : public std::map<std::string , T_ArgValue>
    {
        public:
            ArgNode(std::initializer_list<std::pair<const std::string , T_ArgValue>> init_node)
             : std::map<std::string , T_ArgValue>(init_node)
            {
            }
            /*
            * "Feature : arg name and shortcut in same scope"

            ArgNode(std::initializer_list<std::pair<const std::pair<std::string , std::string> , T_ArgValue>> init_node)
             : std::map<std::pair<std::string , std::string> , T_ArgValue>(init_node)
            {
                std::cout<<"multiple argument"<<std::endl;
            }*/
            ArgNode() = default;
    };
    
    /*static ArgNode<> arg_file {
        {"--tepsource" ,asd},
        {"---s", asd},
    };*/


    /*const ArgNode<ArgNode<>> tepArgs {
        {"new" , arg_new},
        {"compile" , arg_new}
    };*/

    class Arguments
    {
        public:
            static void CheckArgs(int argc , char** argv);
            static Args ArgumentType(const std::string& arg) noexcept;
            static void ArgumentMatcher();
    };
    class ArgBranch
    {
        public:
            
    };
};

#endif