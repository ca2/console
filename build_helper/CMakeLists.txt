cmake_minimum_required(VERSION 3.17)
project(_console_build_helper CXX)


add_executable(_console_build_helper main.cpp)


if (MSVC)
    target_compile_options(_console_build_helper PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_console_build_helper PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_console_build_helper PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


#target_link_options(acme PRIVATE -L . -Wl,-rpath .)


add_dependencies(_console_build_helper acme_${PLATFORM_NAME})


target_link_libraries(_console_build_helper PRIVATE acme)






