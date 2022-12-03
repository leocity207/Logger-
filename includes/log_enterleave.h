#ifndef LOG_ENTERLEAVE_H
#define LOG_ENTERLEAVE_H

#include "log_base.h"

//------------------------------------------------------------------------------------------------------
// This class overide the Log_Base constructor and destructor in order to write the ENTER/LEAVE message
//   This class automaticaly increase/decrease the space counter for better scope tracing inside the log file
//   Like the base class Log_Base, this class is guaranted no except
class Log_EnterLeave final: public Log_Base
{
public:
    explicit Log_EnterLeave(const char* m_message) noexcept(true);

    Log_EnterLeave(const Log_EnterLeave&) = delete;
    Log_EnterLeave operator=(const Log_EnterLeave&) = delete;
    Log_EnterLeave(Log_EnterLeave&&) = delete;
    Log_EnterLeave operator=(Log_EnterLeave&&) = delete;
    ~Log_EnterLeave()  noexcept(true);
private:
    const char* m_message;
};

#endif //LOG_ENTERLEAVE_H