
#include "../includes/log_enterleave.h"


Log_EnterLeave::Log_EnterLeave(const char* message) noexcept(true): m_message(message)
{
    Write_To_Log("ENTER",m_message);
    try
    {
        Log_Base::s_thread_ids[std::this_thread::get_id()].first++;
    }
    catch (...)
    {

    }
}

Log_EnterLeave::~Log_EnterLeave() noexcept(true)
{
    try
    {
        Log_Base::s_thread_ids[std::this_thread::get_id()].first--;
    }
    catch(...)
    {

    }
    Write_To_Log("LEAVE",m_message);
}
