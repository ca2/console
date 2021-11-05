cmake_minimum_required(VERSION 3.17)
project(_console_hellosolarsystem CXX)


add_executable(_console_hellosolarsystem hellosolarsystem.cpp)


if (MSVC)
    target_compile_options(_console_hellosolarsystem PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_console_hellosolarsystem PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_console_hellosolarsystem PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


if(LINUX)
    add_dependencies(_console_hellosolarsystem acme_linux apex_linux)
endif()


target_link_libraries(_console_hellosolarsystem PRIVATE acme apex)


target_include_directories(_console_hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(_console_hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(_console_hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})



target_compile_definitions(_console_hellosolarsystem PRIVATE _CONSOLE__console_hellosolarsystem_LIBRARY)



