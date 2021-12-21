cmake_minimum_required(VERSION 3.17)
project(_console_application_build_helper CXX)


add_executable(_console_application_build_helper
   application_build_helper.cpp
   implement.cpp
   package.cpp)


if (MSVC)
    target_compile_options(_console_application_build_helper PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_console_application_build_helper PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_console_application_build_helper PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


add_dependencies(_console_application_build_helper apex_${PLATFORM_NAME})
add_dependencies(_console_application_build_helper crypto_openssl)
add_dependencies(_console_application_build_helper folder_zip)


target_link_libraries(_console_application_build_helper PRIVATE acme apex)


add_custom_command(
   TARGET _console_application_build_helper
   POST_BUILD
   COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/_console_application_build_helper $ENV{HOME}/bin/application_build_helper
   COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libacme.so $ENV{HOME}/bin/
   COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libacme_linux.so $ENV{HOME}/bin/
   COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libacme_posix.so $ENV{HOME}/bin/
   COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libapex.so $ENV{HOME}/bin/
   COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libapex_linux.so $ENV{HOME}/bin/
   COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libapex_posix.so $ENV{HOME}/bin/
   COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libcrypto_openssl.so $ENV{HOME}/bin/
   COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/libfolder_zip.so $ENV{HOME}/bin/
)



