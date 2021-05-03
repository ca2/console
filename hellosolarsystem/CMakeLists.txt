cmake_minimum_required(VERSION 3.17)
project(hellosolarsystem CXX)


add_executable(hellosolarsystem hellosolarsystem.cpp)


if (MSVC)
    target_compile_options(hellosolarsystem PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(hellosolarsystem PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(hellosolarsystem PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


if(LINUX)
    add_dependencies(hellosolarsystem acme_linux apex_linux)
endif()


target_link_libraries(hellosolarsystem PRIVATE acme apex)


target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})



target_compile_definitions(hellosolarsystem PRIVATE _CONSOLE_HELLOSOLARSYSTEM_LIBRARY)



