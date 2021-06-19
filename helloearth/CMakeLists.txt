cmake_minimum_required(VERSION 3.17)
project(helloearth CXX)


add_executable(helloearth main.cpp)


if (MSVC)
    target_compile_options(helloearth PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(helloearth PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(helloearth PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


add_dependencies(helloearth acme_${PLATFORM_NAME})


target_link_libraries(helloearth PRIVATE acme)


target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(helloearth PRIVATE _CONSOLE_HELLOEARTH_LIBRARY)



