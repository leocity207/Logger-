#include "../includes/log_file.h"
#include "../includes/exception.h"
#include "../includes/time.h"
#include "../includes/process.h"
#include <ctime> 

extern const char* GET_COMMIT_HASH();
extern const char* GET_VERSION();

Log_File::Log_File() noexcept
{
    std::filesystem::path file_path = Get_Log_File_Path();
    file_path = file_path.make_preferred();
    this->m_file_stream = std::ofstream(file_path, std::ios::out);
    if(this->m_file_stream.fail())
    {
        std::cout<< "could not open file :" << file_path << std::endl;
        return;
    }
    
    this->m_file_stream << "##################################################################" << std::endl;
    this->m_file_stream << "Begining of log: " << Get_Current_Time("%A %c") << std::endl;
    this->m_file_stream << "commit hash: " << GET_COMMIT_HASH() << std::endl;
    this->m_file_stream << "version " << GET_VERSION() << std::endl;
    this->m_file_stream << std::endl;
}

Log_File::~Log_File()
{
    try
    {
        this->m_file_stream << std::endl;
        this->m_file_stream << "end of log: " << Get_Current_Time("%A %c") << std::endl;
        this->m_file_stream << "###################################################################" << std::endl;
        this->m_file_stream.close();
    }
    catch (...)
    {
    }
}

std::filesystem::path Log_File::Get_Log_File_Path() noexcept(true)
{
    try
    {
        std::string filename = Get_Current_Time("%F_%H-%M-%S") + "_" + Get_Process_Name() + ".log";
        std::filesystem::path the_path(Get_Log_Dir());
        the_path /= filename;
        return the_path;
    }
    catch (...)
    {
        return std::filesystem::path();
    }
}

Log_File& Log_File::Get() noexcept(true)
{
    static Log_File s_log_file = Log_File();
    return s_log_file;
}

std::ofstream& Log_File::Get_Stream() noexcept(true)
{
    return m_file_stream;
}