cmake_minimum_required(VERSION 3.17)
project(_console_hello CXX)


add_executable(_console_hello main.cpp)


if (MSVC)
    target_compile_options(_console_hello PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_console_hello PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_console_hello PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


#target_link_options(acme PRIVATE -L . -Wl,-rpath .)


add_dependencies(_console_hello acme_${PLATFORM_NAME})


target_link_libraries(_console_hello PRIVATE acme)






