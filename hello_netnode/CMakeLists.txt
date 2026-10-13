cmake_minimum_required(VERSION 3.16)
project(_console_hello CXX)


add_executable(_console_hello main.cpp)


if(${WIN32})
    target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


#target_link_options(${PROJECT_NAME} PRIVATE -L . -Wl,-rpath .)


add_dependencies(_console_hello acme_${OPERATING_SYSTEM_NAME})


target_link_libraries(${PROJECT_NAME} PRIVATE acme)






