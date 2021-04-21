/**
 * This file implements the lexer functions.
 *
 * @author Jakob Kaiser
 */

#include "Lexer.h"

void Lexer::feed(string input) {
    this->input = input;
    this->current_position = 0;
}

Token Lexer::getNextToken() {
    current_character = this->input[current_position];

    while (current_character) {
        if (isspace(current_character)) {
            skipWhitespace();
        } else if (isdigit(current_character)) {
            return getIntegerToken();
        } else if (current_character == 43) {
            advance();
            return Token(PLUS);
        } else if (current_character == 45) {
            advance();
            return Token(MINUS);
        } else if (current_character == 42) {
            advance();
            return Token(MUL);
        } else if (current_character == 47) {
            advance();
            return Token(DIV);
        }
    }

    return Token(END);
}

void Lexer::skipWhitespace() {
    while (current_character && isspace(current_character)) {
        advance();
    }
}

void Lexer::advance() {
    this->current_position += 1;
    this->current_character = this->input[current_position];
}

Token Lexer::getIntegerToken() {
    string result;

    while (current_character && isdigit(current_character)) {
        result.push_back(current_character);
        advance();
    }

    return Token(INTEGER, result);
}
