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

int Interpreter::factor() {
    string value = current_token.getValue();
    eat(INTEGER);
    return stoi(value);
}

int Interpreter::term() {
    int result = factor();
    while (current_token.getType() == MUL ||
           current_token.getType() == DIV) {
        if (current_token.getType() == MUL) {
            eat(MUL);
            result *= factor();
        } else if (current_token.getType() == DIV) {
            eat(DIV);
            result /= factor();
        }
    }

    return result;
}

int Interpreter::expr() {
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

Interpreter::Interpreter() {
    this->lexer = Lexer();
}

void Interpreter::feed(string input) {
    this->lexer.feed(input);
}

int Interpreter::interpret() {
    this->current_token = lexer.getNextToken();
    int result;

    try{
        result = this->expr();
    }
    catch (const SytaxError& e) {
        cerr << e.what();
        exit(-1);
    }

    return result;
}