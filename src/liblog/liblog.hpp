#pragma once

#include <fstream>
#include <string>
#include <vector>

#define BLANK_STR ""

enum class loglevel_t
{
    print = 0,
    errors = 1,
    warnings = 2,
    everything = 3
};

class logger
{
public:
    logger(loglevel_t loglevel, std::string logfile);
    logger(loglevel_t loglevel);

    // use defaults (which are to log everything and set filename to logger.log)
    logger();
    
    // when object is deconstructed, all log history is flushed from the vector into a log file
    ~logger();

    // logging functions
    bool log_error(std::string error_str);
    bool log_warning(std::string warning_str);
    bool log(std::string log_str);

    bool log_value(std::string log_str, int value);
    bool log_value(std::string log_str, double value);

    // print function
    // goes into log_history to be flushed unlike std::cout
    bool print(std::string print_str);
    bool just_print(std::string print_str);

    // called by deconstructor, but can also be called manually
    bool dump_log(std::string file);

private:
    std::vector<std::string> log_history;
    std::string m_logfile;
    loglevel_t m_loglevel;
};