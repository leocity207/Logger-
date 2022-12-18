#ifndef EXCEPTION_H
#define EXCEPTION_H


#include <exception>
#include <string>
#include <iostream>


#include "log.h"



class Exception 
{
public:
    inline constexpr Exception()                            = default;
    inline constexpr Exception(const Exception&)            = default;
    inline constexpr Exception& operator=(const Exception&) = default;
    inline constexpr Exception(Exception&&)                 = default;
    inline constexpr Exception& operator=(Exception&&)      = default;
    virtual ~Exception()                                    = default;
    virtual inline const char* what() const noexcept {return "General exception";};
};


//--------------------------------------------------------------------------------------------
// Same as EXCEPTION_TRACE except that nothing is traced (what() methode still give a message)
// @param name : the name of the class that while be create for the exception
// @param message : a "const char *" like string explaining the exception 
#define DECLARE_EXCEPTION(base,name,message) class name :public base \
{\
public:\
    inline constexpr name()                       = default;\
    inline constexpr name(const name&)            = default;\
    inline constexpr name& operator=(const name&) = default;\
    inline constexpr name(name&&)                 = default;\
    inline constexpr name& operator=(name&&)      = default;\
    ~name()                                       = default;\
    inline const char* what() const noexcept override {return message;};\
};\

//-----------------------------------------------
//Throw exception while tracing what is happening
// @param class  : the class to throw
// @param message: the message to trace
#define THROW(class) \
{\
TRACE_EXCEPTION(class().what());\
throw class();\
}\

#define THROW_TRACE(class,...) \
{\
TRACE_EXCEPTION(__VA_ARGS__);\
throw class();\
}\

#define THROW_ERNNO(class) \
{\
TRACE_EXCEPTION(class().what()," ", strerror(errno));\
throw class();\
}\

#define THROW_FUNC(class,function) \
{\
TRACE_EXCEPTION(function ," Error");\
throw class();\
}\

#endif // !EXCFEPTION_H

