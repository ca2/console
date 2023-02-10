cmake_minimum_required(VERSION 3.16)
project(_console_application_build_helper CXX)


add_executable(_console_application_build_helper
        application_build_helper.cpp
        application.cpp
        package.cpp
        prepare_application.cpp
        prepare_project.cpp
        )


if (MSVC)
    target_compile_options(_console_application_build_helper PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_console_application_build_helper PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_console_application_build_helper PRIVATE "/SUBSYSTEM:CONSOLE")
endif ()


add_dependencies(_console_application_build_helper acme)
add_dependencies(_console_application_build_helper acme_${OPERATING_SYSTEM_NAME})
add_dependencies(_console_application_build_helper acme_posix)
#add_dependencies(_console_application_build_helper apex_${OPERATING_SYSTEM_NAME})
#add_dependencies(_console_application_build_helper apex_posix)
#add_dependencies(_console_application_build_helper crypto_openssl)
#add_dependencies(_console_application_build_helper folder_zip)


target_link_libraries(_console_application_build_helper PRIVATE acme)

target_precompile_headers(_console_application_build_helper PRIVATE framework.h)



add_custom_command(
        TARGET _console_application_build_helper
        POST_BUILD
        COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/_console_application_build_helper ${APPLICATION_BUILD_HELPER}
        COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libacme.so $ENV{HOME}/solution/main/operating-system/tool-linux/bin/
        COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libacme_${OPERATING_SYSTEM_NAME}.so $ENV{HOME}/solution/main/operating-system/tool-linux/bin/
        COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libacme_posix.so $ENV{HOME}/solution/main/operating-system/tool-linux/bin/
        #COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libapex.so $ENV{HOME}/bin/
        #COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libapex_${OPERATING_SYSTEM_NAME}.so $ENV{HOME}/bin/
        #COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libapex_posix.so $ENV{HOME}/bin/
        #COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libcrypto_openssl.so $ENV{HOME}/bin/
        #COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libfolder_zip.so $ENV{HOME}/bin/
)



