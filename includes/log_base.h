#ifndef LOG_BASE_H
#define LOG_BASE_H

#include <string>
#include <thread>
#include <map>
#include <mutex>


//--------------------------------------------------------------------------------------------------------------
// Base class for writting logs inside log file
//   This class is made to handle multiple string working in paralele
//   This class is purely static but can be inhearited for more behaviour (Ex: EnterLeave logs)
//   This class is guaranted no except. if writting log fail, it just won't be written inside the log file
class Log_Base{

public:
    //--------------------------------
    // write the message to the log file
    // @param special : a string to add beffore the message
    template<typename... T>
    static void Write_To_Log(const char* special,T&&... messages) noexcept(true);

protected:
    Log_Base() = default;
    Log_Base(const Log_Base&) = delete;
    Log_Base operator=(const Log_Base&) = delete;
    Log_Base(Log_Base&&) = delete;
    Log_Base operator=(Log_Base&&) = delete;
    ~Log_Base() = default;
    
    //--------------------------------------------------
    // Give the log header containing date and thread ID
    // @return the header for the comming message
    static std::string Get_Log_Header() noexcept(true);

    //--------------------------------------
    // give back the scope leel ofthe message
    // @return : a space string representing the level for the current string
    static std::string Get_Thread_Space_Level() noexcept(true);

    //--------------------------------------------------------
    // Get a new thread ID as a four charachter long string
    // @return : a string representing the thread ID for more redability
    static std::string Get_New_Thread_ID() noexcept(true);
    
    //map containing the thread infos
    static std::map<std::thread::id,std::pair<unsigned int,std::string>> s_thread_ids;

    // the current thread
    static std::thread::id s_current_thread;

    // thread counter used when generating new thread ID
    static unsigned int s_thread_count;
private:
    static std::mutex s_file_mtx;
};

#include "log_base.hpp"

#endif //LOG_BASE_H