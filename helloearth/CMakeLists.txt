cmake_minimum_required(VERSION 3.16)
project(_console_helloearth CXX)


list(APPEND executable_source
        programs/1-2022-02-11-twitch-memoriesdota_file_word_count.cpp
        programs/2-2022-07-11-twitch-korishama_polymorphism.cpp
        programs/3-2022-09-30-twitch-octaelliptical_star.cpp
        programs/4-2022-10-01-twitch-octaelliptical_star_only_odd_line_count.cpp
        programs/5-2022-10-04-twitch-octaelliptical_iterative_fibonacci.cpp
        programs/6-2022-10-05-twitch-octaelliptical_count_miscellaneous_characters.cpp
        programs/7-2022-10-06-twitch-octaelliptical_list_prime_numbers.cpp
        programs/8-2022-11-14-twitch@nicopelullo-binary_tree_to_stack.cpp
        programs/9-2022-11-15-twitch@nicopelullo-inorder__preorder_and_post_order.cpp
        programs/a-2023-02-02-twitch@ca2software.cpp
        application.cpp
        twitch.cpp
        )


add_executable(_console_helloearth ${executable_source})


if (MSVC)
    target_compile_options(_console_helloearth PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_console_helloearth PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_console_helloearth PRIVATE "/SUBSYSTEM:CONSOLE")
endif()


add_dependencies(_console_helloearth acme_${OPERATING_SYSTEM_NAME})


target_link_libraries(_console_helloearth PRIVATE acme)


list(APPEND executable_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND executable_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND executable_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)


target_include_directories(${PROJECT_NAME} PRIVATE ${executable_include_directories})



target_compile_definitions(_console_helloearth PRIVATE _CONSOLE_HELLOEARTH_LIBRARY)



