#include "log_base.h"
#include "log_file.h"
#include "src/utils/misc.h"
#include "src/utils/time.h"
#include <sstream>
#include <string_view>

std::thread::id Log_Base::s_current_thread = std::thread::id();
std::map<std::thread::id,std::pair<unsigned int,std::string>> Log_Base::s_thread_ids = std::map<std::thread::id,std::pair<unsigned int,std::string>> ();
unsigned int Log_Base::s_thread_count = 0;
std::mutex Log_Base::s_file_mtx;


std::string Log_Base::Get_Log_Header() noexcept(true)
{
    try
    {
        std::stringstream tmp_mili;
        tmp_mili << std::right << std::setfill('0') << std::setw(4) << Get_Current_Time_Milissecond();
        return Get_Current_Time("%T") + ":" + tmp_mili.str() + " " + s_thread_ids[std::this_thread::get_id()].second + ": ";
    }
    catch(...)
    {
        return std::string();
    }
}

std::string Log_Base::Get_Thread_Space_Level() noexcept(true)
{
    try
    {
        return std::string("  ") * s_thread_ids[std::this_thread::get_id()].first;
    }
    catch(...)
    {
        return std::string();
    }
}

std::string Log_Base::Get_New_Thread_ID() noexcept(true)
{
    try
    {
        s_thread_count++;
        std::stringstream tmp;
        tmp << std::right << std::setfill('0') << std::setw(4) << std::hex << s_thread_count;
        return tmp.str();
    }
    catch(...)
    {
        return std::string();
    }
}