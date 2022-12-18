#include "../../includes/process.h"
#include <sys/types.h>
#include <unistd.h>
#include "../../includes/exception.h"
#include <string_view>

int Get_Process_ID() noexcept(true)
{
    return (int)getpid();
}
const std::string Get_Process_Name()
{
    std::string_view prog_path = program_invocation_name;
	size_t last_slash = prog_path.rfind('/');
	std::string_view prog_name = prog_path.substr(last_slash+1);
	return std::string(prog_name);
}
const std::filesystem::path Get_Log_Dir()
{
    return "/tmp";
}

const std::filesystem::path GetCurrentProcessPath()
{
    char exelinkpath[64];
	sprintf(exelinkpath, "/proc/%d/exe", getpid());
	std::string total;
	char s[256];
	for (;;) {
		ssize_t nchars = readlink(exelinkpath, s, 256);
		if (nchars < 0)
			THROW_FUNC(OS_Function_Exception,"readlink")
		total.append(s);
		if(nchars < 256)
			break;
	} 
	return std::filesystem::path(s);
}