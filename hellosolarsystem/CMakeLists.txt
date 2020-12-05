cmake_minimum_required(VERSION 3.17)
project(hellosolarsystem CXX)
include(FindPkgConfig)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")
message(STATUS "CMAKE_SYSTEM_NAME is ${CMAKE_SYSTEM_NAME}")



if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(LINUX TRUE)
    set(PLATFORM_NAME "linux")
    include(FindPkgConfig)
elseif(WIN32)
    set(PLATFORM_NAME "windows")
endif()


set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)


add_executable(hellosolarsystem hellosolarsystem.cpp)


if (MSVC)
    target_compile_options(hellosolarsystem PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(hellosolarsystem PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(hellosolarsystem PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


target_link_libraries(hellosolarsystem PRIVATE acme apex aqua)


target_link_directories(hellosolarsystem PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(apex PRIVATE .)
target_include_directories(hellosolarsystem PRIVATE $ENV{HOME}/__config)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})



target_compile_definitions(hellosolarsystem PRIVATE _CONSOLE_HELLOSOLARSYSTEM_LIBRARY)
target_compile_definitions(hellosolarsystem PRIVATE UNICODE)
target_compile_definitions(hellosolarsystem PRIVATE _UNICODE)



