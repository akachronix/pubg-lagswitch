#pragma once

#include <fstream>
#include <string>
#include <vector>

enum class loglevel_t
{
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

    bool log_error(std::string error_str);
    bool log_warning(std::string warning_str);
    bool log(std::string log_str);

    // called by deconstructor, but can also be called manually
    bool dump_log(std::string file);

private:
    std::vector<std::string> log_history;
    std::string m_logfile;
    loglevel_t m_loglevel;
};