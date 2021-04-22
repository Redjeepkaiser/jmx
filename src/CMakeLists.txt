# Add new .cpp files here
set(core_SRCS Token.cpp Lexer.cpp Interpreter.cpp)

add_library(core ${core_SRCS})
add_executable(exe main.cpp)
target_link_libraries(exe core)