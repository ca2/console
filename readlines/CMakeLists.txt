cmake_minimum_required(VERSION 3.17)
project(_console_readlines CXX)




add_executable(_console_readlines main.cpp)


if (MSVC)
    target_compile_options(_console_readlines PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_console_readlines PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_console_readlines PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


target_link_libraries(_console_readlines PRIVATE acme apex aqua)

add_dependencies(_console_readlines apex_${PLATFORM_NAME})


target_include_directories(apex PRIVATE .)
target_include_directories(_console_readlines PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(_console_readlines PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(_console_readlines PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(_console_readlines PRIVATE _CONSOLE__console_readlines_LIBRARY)



