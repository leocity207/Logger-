#ifndef MISC_H
#define MISC_H

#include <string>

//----------------------------
// operator used to multiply a string with a number just like in python
// @param a : the string to multiply
// @param b : the number of time to repeat the string
// @return  : a concatenate b time with itself 
std::string operator*(std::string&& a, unsigned int b);

#endif //MISC_H


