cmake_minimum_required(VERSION 3.17)
project(helloearth CXX)


#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")


if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(LINUX TRUE)
    set(PLATFORM_NAME "linux")
    include(FindPkgConfig)
elseif(WIN32)
    set(PLATFORM_NAME "windows")
endif()


set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)


add_executable(helloearth main.cpp)


if (MSVC)
    target_compile_options(helloearth PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(helloearth PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(helloearth PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


if(LINUX)
    add_dependencies(helloearth acme_linux)
endif()


target_link_libraries(helloearth PRIVATE acme)

target_link_directories(helloearth PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(helloearth PRIVATE .)
target_include_directories(helloearth PRIVATE $ENV{HOME}/__config)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(helloearth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})



target_compile_definitions(helloearth PRIVATE _CONSOLE_HELLOEARTH_LIBRARY)
target_compile_definitions(helloearth PRIVATE UNICODE)
target_compile_definitions(helloearth PRIVATE _UNICODE)


