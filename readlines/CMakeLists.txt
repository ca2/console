cmake_minimum_required(VERSION 3.16)
project(_console_readlines CXX)




add_executable(${PROJECT_NAME} application.cpp main.cpp)


if(${WIN32})
    target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


target_link_libraries(${PROJECT_NAME} PRIVATE static_acme)
if(${WINDOWS_DESKTOP})
target_link_libraries(${PROJECT_NAME} PRIVATE static_acme_windows_common)
target_link_libraries(${PROJECT_NAME} PRIVATE static_acme_windows)
elseif(${FREEBSD})
target_link_libraries(${PROJECT_NAME} PRIVATE static_acme_posix)
target_link_libraries(${PROJECT_NAME} PRIVATE static_acme_darwin)
target_link_libraries(${PROJECT_NAME} PRIVATE static_acme_freebsd)
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE static_apex)
if(${WINDOWS_DESKTOP})
target_link_libraries(${PROJECT_NAME} PRIVATE static_apex_windows_common)
target_link_libraries(${PROJECT_NAME} PRIVATE static_apex_windows)
elseif(${FREEBSD})
target_link_libraries(${PROJECT_NAME} PRIVATE static_apex_posix)
target_link_libraries(${PROJECT_NAME} PRIVATE static_apex_darwin)
target_link_libraries(${PROJECT_NAME} PRIVATE static_apex_freebsd)
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE static_aqua)
if(${FREEBSD})
target_link_libraries(${PROJECT_NAME} PRIVATE procstat kvm)
endif()
target_compile_definitions(${PROJECT_NAME} PRIVATE CUBE)

#add_dependencies(${PROJECT_NAME} apex_${OPERATING_SYSTEM_NAME})
#add_dependencies(${PROJECT_NAME} crypto_openssl)
#add_dependencies(${PROJECT_NAME} folder_zip)


list(APPEND executable_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND executable_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND executable_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)


target_include_directories(${PROJECT_NAME} PRIVATE ${executable_include_directories})


target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)



