cmake_minimum_required(VERSION 3.16)
project(_console_build CXX)


add_executable(_console_build build.cpp)


if (MSVC)
   target_compile_options(_console_build PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(_console_build PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(_console_build PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


add_dependencies(_console_build apex_${PLATFORM_NAME})


target_link_libraries(_console_build PRIVATE acme)
target_link_libraries(_console_build PRIVATE apex)
target_link_libraries(_console_build PRIVATE build)




