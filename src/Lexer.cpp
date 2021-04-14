#include "Lexer.h"
//int Interpreter::get_integer() {
//    std::string complete_integer;
//
//    while (std::isdigit(this->current_char)) {
//        complete_integer.append(this->current_char);
//        this->current_position += 1;
//        this->current_char = this->text[this->current_position];
//    }
//
//    return std::stoi(complete_integer);
//}
//
//Token Interpreter::get_next_token() {
//    while (this->current_char) {
//
//        if (std::isdigit(this->current_char)) {
//            return Token(this->get_integer());
//        } else if (this->current_char.is_whitespace()) {
//        } else if (this->current_char == "+") {
//        } else if (this->current_char == "-") {
//        }
//    }
//}
//
//int Interpreter::interpret(std::string input) {
//    text = input;
//    current_position = 0;
//    current_char = text[current_position];
//
//    current_token = get_next_token();
//    return 0;
//}