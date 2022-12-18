add_library(log OBJECT                       
    src/log_base.cpp
    src/log_file.cpp
    src/log_enterleave.cpp
    src/misc.cpp
    src/time.cpp
)

if(WIN32)
    target_sources(log PRIVATE
        src/windows/process.cpp
    )
elseif(UNIX)
    target_sources(log PRIVATE
        src/linux/process.cpp
    )
else()
    message( FATAL_ERROR " this platform is not supported" )
endif()

target_link_libraries(log)