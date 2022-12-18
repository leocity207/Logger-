#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <windows.h>
#include <array>

#include "../../includes/process.h"
#include "../../includes/misc.h"
#include "../../includes/exception.h"
#include "wstring.h"



int Get_Process_ID() noexcept(true)
{
    return GetCurrentProcessId();
}

const std::string Get_Process_Name()
{
	std::array<TCHAR, MAX_PATH + 1> szExePath = {};
	if (GetModuleFileName(GetModuleHandle(NULL), szExePath.data(), MAX_PATH) == 0)
		throw OS_Function_Exception();
	TCHAR* szExeName = strrchr(szExePath.data(), '\\');
	if (szExeName == NULL)
		szExeName = szExePath.data();
	#pragma warning( disable : 26481) // this is very simple arithmetic
	else
		szExeName++;
	TCHAR* szExt = strrchr(szExeName, '.');
	if (szExt != NULL)
		*szExt = '\0';
	return TO_STRING(szExeName);
}

const std::filesystem::path Get_Log_Dir()
{
	std::array<TCHAR, MAX_PATH + 1> lpTempPathBuffer = {};
	DWORD dwRetVal = 0;
	dwRetVal = GetTempPath(MAX_PATH, lpTempPathBuffer.data());
	if (dwRetVal > MAX_PATH || (dwRetVal == 0))
    {
        throw OS_Function_Exception();
    }
    return std::filesystem::path(lpTempPathBuffer.data());
}


const std::filesystem::path GetCurrentProcessPath()
{
	std::array<TCHAR, MAX_PATH + 1> szExePath = {};
	if (GetModuleFileName(GetModuleHandle(NULL), szExePath.data(), MAX_PATH) == 0)
		throw OS_Function_Exception();
	return std::filesystem::path(szExePath.data());
}