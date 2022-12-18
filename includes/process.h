#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <filesystem>

#include "exception.h"

DECLARE_EXCEPTION(Exception,OS_Function_Exception,"OS function returned with exception.")
//-------------------------
// Give back the process ID
// @return : the process ID
int Get_Process_ID() noexcept(true);

//-------------------------
// Give back the process name
// @return : the process name
const std::string Get_Process_Name();

//-------------------------
// Give back the log directory
// @return : the log directory
const std::filesystem::path Get_Log_Dir();

//-------------------------
// Give back the current process path
// @return : the current process path
const std::filesystem::path GetCurrentProcessPath();

#endif //PROCESS_H