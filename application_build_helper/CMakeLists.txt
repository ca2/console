cmake_minimum_required(VERSION 3.16)
project(_console_application_build_helper CXX)


add_executable(${PROJECT_NAME}
        application_build_helper/application_build_helper.cpp
        application_build_helper/application_build_helper.h
        application_build_helper/package.cpp
        application_build_helper/prepare_application.cpp
        application_build_helper/prepare_project.cpp
        application.cpp
        application.h
        generate_documentation.cpp
        )


if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:CONSOLE")
endif ()


add_dependencies(${PROJECT_NAME} acme)
add_dependencies(${PROJECT_NAME} acme_${OPERATING_SYSTEM_NAME})
add_dependencies(${PROJECT_NAME} acme_posix)
#add_dependencies(_console_application_build_helper apex_${OPERATING_SYSTEM_NAME})
#add_dependencies(_console_application_build_helper apex_posix)
#add_dependencies(_console_application_build_helper crypto_openssl)
#add_dependencies(_console_application_build_helper folder_zip)


target_link_libraries(${PROJECT_NAME} PRIVATE acme)

target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
#list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})


add_custom_command(
        TARGET _console_application_build_helper
        POST_BUILD
        COMMAND mkdir -p $ENV{HOME}/bin
        COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/_console_application_build_helper ${APPLICATION_BUILD_HELPER}
        COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libacme.so $ENV{HOME}/bin/
        COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libacme_${OPERATING_SYSTEM_NAME}.so $ENV{HOME}/bin/
        COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libacme_posix.so $ENV{HOME}/bin/
        #COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libapex.so $ENV{HOME}/bin/
        #COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libapex_${OPERATING_SYSTEM_NAME}.so $ENV{HOME}/bin/
        #COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libapex_posix.so $ENV{HOME}/bin/
        #COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libcrypto_openssl.so $ENV{HOME}/bin/
        #COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libfolder_zip.so $ENV{HOME}/bin/
)



