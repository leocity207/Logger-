add_library(log OBJECT                       
    src/log_base.cpp
    src/log_file.cpp
    src/log_enterleave.cpp
    src/misc.cpp
    src/time.cpp
)

target_link_libraries(log)