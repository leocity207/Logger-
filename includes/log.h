#ifndef LOG_H
#define LOG_H

#include "log_base.h"
#include "log_enterleave.h"



#define DEBUG
#ifdef DEBUG

// file to include to get all the log functionality
#define TRACE(...)           Log_Base::Write_To_Log("[info]",__VA_ARGS__);
#define TRACE_EXCEPTION(...) Log_Base::Write_To_Log("[Exception]","file: ",std::filesystem::path(__FILE__).filename()," at line : ",__LINE__," :",__VA_ARGS__);
#define TRACE_ERROR(...)     Log_Base::Write_To_Log("[Error]"    ,"file: ",std::filesystem::path(__FILE__).filename()," at line : ",__LINE__," :",__VA_ARGS__);
#define TRACE_DEBUG(...)     Log_Base::Write_To_Log("[Debug]",__VA_ARGS__);

#define TRACE_RETURN(trace_type,value,...) {Log_Base::Write_To_Log(trace_type,__VA_ARGS__); return value;};


//---------------------------------------------------------------------
// Used for tracing the fact that we are entering or leaving a function
// This is used to know the scope of an occuring error
#define TRACE_ENTERLEAVE(x) Log_EnterLeave _(x);

#else

#define TRACE(...)           
#define TRACE_EXCEPTION(...) 
#define TRACE_ERROR(...)     
#define TRACE_DEBUG(...)   
#define TRACE_ENTERLEAVE(x)  
#define TRACE_RETURN(trace_type,value,...) return value;

#endif //DEBUG_TRACE

#endif