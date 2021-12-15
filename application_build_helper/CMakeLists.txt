cmake_minimum_required(VERSION 3.17)
project(_console_application_build_helper CXX)


add_executable(_console_application_build_helper application_build_helper.cpp)


if (MSVC)
    target_compile_options(_console_application_build_helper PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_console_application_build_helper PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_console_application_build_helper PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


add_dependencies(_console_application_build_helper acme_${PLATFORM_NAME})


target_link_libraries(_console_application_build_helper PRIVATE acme)


add_custom_command(
   TARGET _console_application_build_helper
   POST_BUILD
   COMMAND __write_platform_to_cmake_binary_dir
   COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/_console_application_build_helper ${APPLICATION_BUILD_HELPER}
)



