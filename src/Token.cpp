#include "Token.h"

Token::Token(TokenType type, string value) {
    this->type = type;
    this->value = value;
}

Token::Token(TokenType type) {
    this->type = type;
}

TokenType Token::getType() {
    return this->type;
}

string Token::getValue() {
    return this->value;
}