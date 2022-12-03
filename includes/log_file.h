#ifndef LOG_FILE_H
#define LOG_FILE_H

#include <fstream>
#include <filesystem>
#include <iostream>
#include <mutex>

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Represent the file where logs are written to.
// |  This class handle the creation of the file, the Header and footer of the file, 
// |  |  It also Write information about the current process and the current commit
// |  This class is a singleton wich mean that each process only get access to the one log file
// |  This class is guaranted noexcept wich mean that it will always return a stream
// |  |  It should be check if stream is still good to use before sending data into the stream
class Log_File final
{
private:
	std::ofstream m_file_stream; 
	Log_File() noexcept;
	Log_File(const Log_File&) = delete;
	Log_File operator=(const Log_File&) = delete;
	Log_File(Log_File&&) = delete;
	Log_File operator=(Log_File&&) = delete;
	~Log_File();
	static std::mutex s_file_mtx;
public:
	//----------------------------------------
	// give back the only instance of log file
	// @return : the signle instance of Log_file
	static Log_File& Get() noexcept(true); 

	//----------------------------------------
	// give back the path to the log file
	// @return : the path to the logfile
	static std::filesystem::path Get_Log_File_Path() noexcept(true);

	//------------------------------------
	// get the stream wher we can write to
	// @return : give back the stream where you can write to the log file
	std::ofstream& Get_Stream() noexcept(true);
};

#endif //LOG_FILE_H