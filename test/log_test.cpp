#include "log_test.h"
#include "../log.h"
#include <thread>
#include "src/exception/exception.h"
#include <chrono>

//--------------------------
// Level definition function
void level_2();
void level_3();
void level_4();
void level_2()
{
    TRACE_ENTERLEAVE("level 2")
    level_3();
}
void level_3()
{
    TRACE_ENTERLEAVE("level 3")
    level_4();
}
void  level_4()
{
    TRACE_ENTERLEAVE("level 3")
    std::this_thread::sleep_for(std::chrono::seconds(1));

}
void func1()
{
    TRACE_ENTERLEAVE("func1")
    level_2();
}

//---------------------------------
// printing differnet kind of trace
void func2()
{
    TRACE_ENTERLEAVE("func2")
    TRACE_ERROR("This is an error.");
    TRACE_DEBUG("This is a debug trace.");
    TRACE_EXCEPTION("This is an Exception trace.");
    TRACE("this is a plain trace");    
}




TEST(Log_Test, thread_tracing) {
    TRACE_ENTERLEAVE("LOG TEST 1")
    TRACE("Main thread");
    std::thread t1(func1);
    std::thread t2(func2); 
    TRACE("All thread launched");
    t1.join();
    t2.join();
    TRACE("test finished");
}


// throw test function
void throw_test()
{
    TRACE_ENTERLEAVE("throw_test")
    try{
        THROW(Exception)
    }
    catch(const Exception&){
        TRACE("caught general exception");
    }

    try{
        THROW_TRACE(Exception," This is a comment")
    }
    catch(const Exception&){
        TRACE("caught general exception with comment");
    }


    

#ifdef linux
    try{
        THROW_ERNNO(Exception)
    }
    catch(const Exception&)
    {
        TRACE("caught Ernno excpetion");
    }
#endif

    try{
        THROW_FUNC(Exception, "the_func")
    }
    catch(const Exception&)
    {
        TRACE("Function Exception Caught");
    }
}

TEST(Log_Test, throwing) {
    TRACE_ENTERLEAVE("LOG TEST 2")
    std::thread t1(throw_test);
    t1.join();
}



TEST(Log_Test, variadic) {
    TRACE_ENTERLEAVE("LOG TEST 3")
    TRACE("messsage 1 ", "following message. ","Now some numbers: ", 1 , " ",1.2 , " final message" );
    const char* a = "static message ";
    std::string b = "static string message";
    TRACE(a,b);
    b  = a;
}