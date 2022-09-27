cmake_minimum_required(VERSION 3.16)
project(_console_hellosolarsystem CXX)


add_executable(_console_hellosolarsystem hellosolarsystem.cpp)


if (MSVC)
    target_compile_options(_console_hellosolarsystem PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_console_hellosolarsystem PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_console_hellosolarsystem PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


if(LINUX)
    add_dependencies(_console_hellosolarsystem acme_linux apex_linux)
elseif(FREEBSD)
    add_dependencies(_console_hellosolarsystem acme_freebsd apex_freebsd)
endif()


add_dependencies(_console_hellosolarsystem crypto_openssl)
add_dependencies(_console_hellosolarsystem folder_zip)


target_link_libraries(_console_hellosolarsystem PRIVATE acme apex)


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories folder_zip)


target_compile_definitions(_console_hellosolarsystem PRIVATE _CONSOLE_HELLOSOLARSYSTEM_LIBRARY)



