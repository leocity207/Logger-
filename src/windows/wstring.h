#ifndef WSTRING_H
#define WSTRING_H

#include <string>

std::wstring To_Wide_String(const std::string& utf8Str);

std::string To_String(const std::wstring& utf16Str);


#ifndef UNICODE 
	#define TO_STRING(x) std::string(x)
    #define TO_TSTRING(x) x.c_str()
#else
	#define TO_STRING(x) To_String(std::wstring(x)) 
    #define TO_TSTRING(x) To_Wide_String(x).c_str()
#endif


#endif //WSTRING_H