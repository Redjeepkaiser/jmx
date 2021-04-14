#include "Token.h"

int main(){
    std::string input;
    Interpreter interpreter = Interpreter();

    while (std::getline(std::cin, input)){
        std::cout << interpreter.interpret(input);
    }

    return 0;
}
