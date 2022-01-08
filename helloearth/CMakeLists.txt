cmake_minimum_required(VERSION 3.16)
project(_console_helloearth CXX)


add_executable(_console_helloearth main.cpp)


if (MSVC)
    target_compile_options(_console_helloearth PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_console_helloearth PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_console_helloearth PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


add_dependencies(_console_helloearth acme_${PLATFORM_NAME})


target_link_libraries(_console_helloearth PRIVATE acme)


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(_console_helloearth PRIVATE _CONSOLE__console_helloearth_LIBRARY)



