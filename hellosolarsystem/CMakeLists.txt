cmake_minimum_required(VERSION 3.17)
project(hellosolarsystem CXX)

set(CMAKE_CXX_STANDARD 14)


set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../../../time-windows/cmake)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../../../time-windows/cmake)



if(WIN32)
    set(PLATFORM_NAME "windows")
endif()




add_executable(hellosolarsystem hellosolarsystem.cpp)



if (MSVC)
    target_compile_options(hellosolarsystem PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(hellosolarsystem PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(hellosolarsystem PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


target_link_directories(hellosolarsystem PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_libraries(hellosolarsystem PRIVATE acme apex)


target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(hellosolarsystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})



target_compile_definitions(hellosolarsystem PRIVATE _ACME_LIBRARY)
target_compile_definitions(hellosolarsystem PRIVATE UNICODE)
target_compile_definitions(hellosolarsystem PRIVATE _UNICODE)



