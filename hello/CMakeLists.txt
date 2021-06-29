cmake_minimum_required(VERSION 3.17)
project(hello CXX)


add_executable(hello main.cpp)


if (MSVC)
    target_compile_options(hello PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(hello PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(hello PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


add_dependencies(hello acme_${PLATFORM_NAME})


target_link_libraries(hello PRIVATE acme)






