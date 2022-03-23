# Add new .cpp files here
set(JMX_SRCS
    Lexer.cpp
    Interpreter.cpp
    ./AST/Token.cpp
    ./AST/Num.cpp
    ./AST/BinOp.cpp)

add_library(jmx ${JMX_SRCS})
add_executable(jmx-compiler main.cpp)
target_link_libraries(jmx-compiler jmx)
