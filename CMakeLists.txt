cmake_minimum_required(VERSION 3.20)

project(auxum)

file(
    GLOB_RECURSE
    ${PROJECT_NAME}_SRC
        "src/*.c"
)

file(
    GLOB_RECURSE
    ${PROJECT_NAME}_TEST_SRC
        "test/main.c"
)

add_library(
    ${PROJECT_NAME}
    STATIC
        ${${PROJECT_NAME}_SRC}
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        "inc/"
    PRIVATE
        "inc/auxum"
)

target_compile_definitions(
    ${PROJECT_NAME}
    PRIVATE
        BUILD_TYPE_${CMAKE_BUILD_PLATFORM}
)

set_property(
    TARGET ${PROJECT_NAME}
    PROPERTY C_STANDARD 17
)

if(BUILD_TESTS)
add_executable(
    ${PROJECT_NAME}_test
    ${${PROJECT_NAME}_TEST_SRC}
)

target_compile_options(${PROJECT_NAME}_test PRIVATE -Wall -Wextra -Wpedantic -Werror)

target_link_libraries(
    ${PROJECT_NAME}_test
    PUBLIC
        ${PROJECT_NAME}
)

target_compile_definitions(
    ${PROJECT_NAME}_test
    PRIVATE
        BUILD_TYPE_${CMAKE_BUILD_PLATFORM}
)

set_property(
    TARGET ${PROJECT_NAME}_test
    PROPERTY C_STANDARD 17
)
endif()

