#include "log_base.h"
#include "log_file.h"



template<typename... T>
void Log_Base::Write_To_Log(const char* special,T&&... messages) noexcept(true)
{
    try
    {
        if (s_current_thread != std::this_thread::get_id())
        {
            s_current_thread = std::this_thread::get_id();
            Log_File::Get().Get_Stream() << std::endl;
            s_thread_ids.try_emplace(std::this_thread::get_id(), std::move(std::pair(0, Log_Base::Get_New_Thread_ID())));
        }
        s_file_mtx.lock();
        Log_File::Get().Get_Stream() << Log_Base::Get_Log_Header() << Log_Base::Get_Thread_Space_Level() << special << " ";
        (Log_File::Get().Get_Stream() << ... << messages) << std::endl;
        s_file_mtx.unlock();
    }
    catch (...)
    {
        s_file_mtx.unlock();
    }
}