#ifndef TEP_ASSERT
#define TEP_ASSERT

#include <iostream>
#include <chrono>
#include <unordered_map>
#include <boost/format.hpp>
#include <windows.h>
#include <sstream>
#include <iomanip>

namespace tep
{
    /*
        e.g:
            [LOG] : "Lorem ipsum dolor sit amet."
    */
    static constexpr char lb = '[';
    static constexpr char rb = ']';
    static constexpr char sm = ':';
    static constexpr char br = ' ';
    static constexpr char qu = '"';
    
    enum attribute
    {
        __LOG,
        __ASSERT,
        __ERROR,
        __DEBUG,
        __WARN,
    };
    
    static std::unordered_map<attribute , std::pair<std::string , uint16_t>> attributes = 
    {
        {attribute::__LOG , {"LOG" , 30}},
        {attribute::__ASSERT , {"ASSERT" , 32}},
        {attribute::__ERROR , {"ERROR" , 31}},
        {attribute::__DEBUG , {"DEBUG" , 34}},
        {attribute::__WARN , {"WARN" , 37}}
    };


    static inline void Log(const std::string& message) noexcept
    {
        std::cout << message << std::endl;
    }
    /*
    static void LogAtStr(const std::string& attribute , const std::string& message)
    {
                //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                //SetConsoleTextAttribute(hConsole , 12);
        int colorCode = 30;
        std::map<std::string , int> equals{
            {"LOG" , 30},
            {"ASSERT" , 32},
            {"ERROR" , 31},
            {"DEBUG" , 34},
            {"WARN" , 37},
        };

        std::map<std::string , int>::iterator iter = std::find_if(equals.begin() , equals.end() , [attribute](std::string s) { return attribute == s;});


        std::cout << "\033[1;"<<iter->second<<"m"
                    << br
                    << lb << attribute << rb 
                    << br << sm << br
                    << qu << message << qu 
                    << "\033[0m"<<
        std::endl;
    }*/
    static inline void LogAt(const attribute& attribute , const std::string& message)
    {
                //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                //SetConsoleTextAttribute(hConsole , 12);
        int colorCode = 30;
        switch (attribute)
        {
            case attribute::__LOG: colorCode = 30; break;
            case attribute::__ASSERT: colorCode = 32; break;
            case attribute::__ERROR: colorCode = 31; break;
            case attribute::__DEBUG: colorCode = 34; break;
            case attribute::__WARN: colorCode = 37; break;
            default: colorCode = 30; break;
        }
        const std::string msg = str(boost::format("\033[1;%1%m\"%2%\"\033[0m") % colorCode % message);
        std::cout << msg << std::endl;
    }
    static inline void Log(const std::string& time , const std::string& message)
    {
        const std::string msg = str(boost::format("[%1%] : \"%2%\"") % time % message);
        std::cout << msg << std::endl;
    }
    static inline void Log(const std::string& time , const std::string& attribute , const std::string& message)
    {
                //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                //SetConsoleTextAttribute(hConsole , 12);
        int colorCode = 30;

        if(attribute == "LOG") colorCode = 30;
        else if(attribute == "ASSERT") colorCode = 32;
        else if(attribute == "ERROR") colorCode = 31;
        else if(attribute == "DEBUG") colorCode = 34;
        else if(attribute == "WARN") colorCode = 37;

        std::cout << "\033[1;"<<colorCode<<"m"
                    << lb << time << rb 
                    << br
                    << lb << attribute << rb 
                    << br << sm << br
                    << qu << message << qu 
                    << "\033[0m"<<
        std::endl;
    }
    static inline void Log(const std::string& time , const attribute& attribute , const std::string& message)
    {
        std::cout 
                    << lb << time << rb 
                    << br
                    << lb << attributes[attribute].first << rb 
                    << br << sm << br
                    << qu << message << qu 
                    << 
        std::endl;
    }
    static inline void Log(const std::chrono::system_clock::time_point& timePoint , const std::string& attribute , const std::string& message)
    {
        const time_t time = std::chrono::system_clock::to_time_t(timePoint);
        std::stringstream result;
        result << std::put_time(std::localtime(&time) , "%Y-%m-%d %H:%M:%S");
        Log(result.str() , attribute , message);
    }
    static inline void Log(const std::chrono::system_clock::time_point& timePoint , const attribute& attribute , const std::string& message)
    {
        const time_t time = std::chrono::system_clock::to_time_t(timePoint);
        std::stringstream result;
        result << std::put_time(std::localtime(&time) , "%Y-%m-%d %H:%M:%S");
        Log(result.str() , attributes[attribute].first , message);
    }
};

#endif