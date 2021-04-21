cmake_minimum_required(VERSION 3.14)
project(Test)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

# Add files containing new tests here
set(test_SRCS LexerTest.cpp InterpreterTest.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(RunTests RunTests.cpp ${test_SRCS})
target_link_libraries(RunTests gtest_main gmock core)

include(GoogleTest)
gtest_discover_tests(RunTests)