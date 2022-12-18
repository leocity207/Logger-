#include "../includes/misc.h"

std::string operator*(std::string&& a, unsigned int b)
{
    std::string output = "";
    while (b--) {
        output += a;
    }
    return output;
}