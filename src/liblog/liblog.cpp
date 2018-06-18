#include "liblog.hpp"

#include <iostream>
#include <string>


logger::logger(loglevel_t loglevel, std::string logfile)
{
    m_loglevel = loglevel;
    m_logfile = logfile;
}

logger::logger(loglevel_t loglevel)
{
    m_loglevel = loglevel;
}

logger::logger()
{
    // use defaults (which are to log everything and set filename to logger.log)
    m_loglevel = loglevel_t::everything;
    m_logfile = "logger.log";
}

logger::~logger()
{
    dump_log(m_logfile);
}

bool logger::log_error(std::string error_str)
{
    if (m_loglevel >= loglevel_t::errors)
    {
        std::string message = "[ERROR] " + error_str + "\n";

        std::cout << message;
        log_history.push_back(message);

        return true;
    }
    
    return false;
}

bool logger::log_warning(std::string warning_str)
{
    if (m_loglevel >= loglevel_t::warnings)
    {
        std::string message = "[WARNING] " + warning_str + "\n";

        std::cout << message;
        log_history.push_back(message);

        return true;
    }

    return false;
}

bool logger::log(std::string log_str)
{
    if (m_loglevel >= loglevel_t::everything)
    {
        std::string message = "[LOG] " + log_str + "\n";
        
        std::cout << message;
        log_history.push_back(message);

        return true;
    }

    return false;
}

bool logger::dump_log(std::string file)
{
    if(!log_history.empty())
    {
        std::ofstream log_file;
        log_file.open(file);

        if(log_file.is_open())
        {
            for(auto x : log_history)
            {
                log_file << x;
            }
            
            log_file.close();
            log_history.clear();

            return true;
        }
    }

    return false;
}
