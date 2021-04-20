cmake_minimum_required(VERSION 3.17)
project(readlines CXX)




add_executable(readlines main.cpp)


if (MSVC)
    target_compile_options(readlines PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(readlines PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(readlines PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


target_link_libraries(readlines PRIVATE acme apex aqua)

add_dependencies(readlines apex_linux)


target_include_directories(apex PRIVATE .)
target_include_directories(readlines PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(readlines PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(readlines PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(readlines PRIVATE _CONSOLE_READLINES_LIBRARY)



