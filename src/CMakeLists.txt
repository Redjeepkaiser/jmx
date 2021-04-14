set(core_SRCS Token.cpp Parser.cpp Lexer.cpp)

add_library(core ${core_SRCS})
add_executable(exe main.cpp)
target_link_libraries(exe core)