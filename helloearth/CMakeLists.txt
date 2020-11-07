cmake_minimum_required(VERSION 3.17)
project(helloearth CXX)


set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../../../time-windows/cmake)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../../../time-windows/cmake)


set(CMAKE_CXX_STANDARD 14)


if(WIN32)
    set(PLATFORM_NAME "windows")
endif()


add_executable(helloearth main.cpp)


if (MSVC)
    target_compile_options(helloearth PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(helloearth PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(helloearth PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


target_link_directories(helloearth PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_libraries(helloearth PRIVATE acme)


target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})



target_compile_definitions(helloearth PRIVATE _ACME_LIBRARY)
target_compile_definitions(helloearth PRIVATE UNICODE)
target_compile_definitions(helloearth PRIVATE _UNICODE)



