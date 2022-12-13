cmake_minimum_required(VERSION 3.16)
project(_console_readlines CXX)




add_executable(_console_readlines application.cpp)


if (MSVC)
    target_compile_options(_console_readlines PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_console_readlines PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_console_readlines PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


target_link_libraries(_console_readlines PRIVATE acme apex aqua)

add_dependencies(_console_readlines apex_${OPERATING_SYSTEM_NAME})
add_dependencies(_console_readlines crypto_openssl)
add_dependencies(_console_readlines folder_zip)


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})



target_compile_definitions(_console_readlines PRIVATE _CONSOLE_READLINES_LIBRARY)



