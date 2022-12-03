#ifndef TIME_H
#define TIME_H

#include <string>
#include <ostream>

//---------------------------------------------------------
// Give back the current time in the given format
// Format should be formed as the std::strftime function
// @param format : the format in wich to represent the time
// @return       : a string representing the current time
std::string Get_Current_Time(const char * format);

//---------------------------------------------
// give the current second milisecond ranging from 0 to 9999
// @return : the current second in milissecond
std::string Get_Current_Time_Milissecond();

#endif //TIME_H
