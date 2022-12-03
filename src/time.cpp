
#include <ctime>
#include <chrono>
#include <iomanip>
#include <string>
#include <ostream>
#include <sstream>
#include <string_view>
#include <array>

std::string Get_Current_Time(const char * format)
{
    const auto now = std::chrono::system_clock::now();
    const auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::string mbstr(' ', 100);
    struct tm buf;
    #ifdef _WIN32
        localtime_s(&buf, &in_time_t);
    #elif defined(linux)
        localtime_r(&in_time_t,&buf);
    #else
        #error "system not suppported"
    #endif
    const size_t size = std::strftime(&*mbstr.begin(), 100, format, &buf);
    mbstr.resize(size);
    return mbstr;
}

std::string Get_Current_Time_Milissecond()
{
    const std::chrono::high_resolution_clock::time_point t = std::chrono::high_resolution_clock::now();
    std::stringstream tmp;
    tmp << (t.time_since_epoch().count() % 1000);
    return tmp.str();
}