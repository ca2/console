cmake_minimum_required(VERSION 3.16)
project(_console_helloearth CXX)


list(APPEND executable_source
        programs/01-2022-02-11-twitch-memoriesdota_file_word_count.cpp
        programs/02-2022-07-11-twitch-korishama_polymorphism.cpp
        programs/03-2022-09-30-twitch-octaelliptical_star.cpp
        programs/04-2022-10-01-twitch-octaelliptical_star_only_odd_line_count.cpp
        programs/05-2022-10-04-twitch-octaelliptical_iterative_fibonacci.cpp
        programs/06-2022-10-05-twitch-octaelliptical_count_miscellaneous_characters.cpp
        programs/07-2022-10-06-twitch-octaelliptical_list_prime_numbers.cpp
        programs/08-2022-11-14-twitch@nicopelullo-binary_tree_to_stack.cpp
        programs/09-2022-11-15-twitch@nicopelullo-inorder__preorder_and_post_order.cpp
        main.cpp
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


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})



target_compile_definitions(_console_helloearth PRIVATE _CONSOLE_HELLOEARTH_LIBRARY)



