cmake_minimum_required(VERSION 3.14)
project(jmx)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        UnitTests
        test/UnitTests.cpp
        test/TokenTest.cpp
        test/ParserTest.cpp
)
target_link_libraries(
        UnitTests
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(UnitTests)