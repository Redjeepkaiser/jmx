/**
 * This file implements the interpreter functions.
 *
 * @author Jakob Kaiser
 */

#include "Errors.h"
#include "Interpreter.h"

void Interpreter::eat(TokenType type) {
    if (this->current_token.getType() == type) {
        this->current_token = this->lexer.getNextToken();
    } else {
        throw SytaxError();
    }
}

int Interpreter::term() {
    string value = current_token.getValue();
    eat(INTEGER);
    return stoi(value);
}

Interpreter::Interpreter() {
    this->lexer = Lexer();
}

void Interpreter::feed(string input) {
    this->lexer.feed(input);
}

int Interpreter::interpret() {
    this->current_token = lexer.getNextToken();

    int result = term();
    while (current_token.getType() == PLUS ||
           current_token.getType() == MINUS) {
        if (current_token.getType() == PLUS) {
            eat(PLUS);
            result += term();
        } else if (current_token.getType() == MINUS) {
            eat(MINUS);
            result -= term();
        }
    }

    return result;
}