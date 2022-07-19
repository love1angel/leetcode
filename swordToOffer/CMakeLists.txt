cmake_minimum_required(VERSION 3.20)
project(swordToOfferUT)

add_compile_options(-Werror)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(tests)

set(HEAD
        q03.hh)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/733f875989a6fba05f4c366ea7b2ba4054994a7e.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# add test
enable_testing()

add_executable(
        ${PROJECT_NAME}
        ${HEAD}
)

target_link_libraries(
        ${PROJECT_NAME}
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
