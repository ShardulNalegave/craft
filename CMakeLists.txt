cmake_minimum_required(VERSION 3.10)
project(craft LANGUAGES C VERSION 0.1.0)

find_package(Threads REQUIRED)

set(CRAFT_SOURCES
    "src/craft.c")

add_library(craft ${CRAFT_SOURCES})
target_link_libraries(craft PRIVATE Threads::Threads)

target_include_directories(craft
    PRIVATE
        "src/include"
    PUBLIC
        "include"
)
