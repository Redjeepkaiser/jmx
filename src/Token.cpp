#include "Token.h"

Token::Token(TokenType type, string value) {
    this->type = type;
    this->value = value;
}

int Token::getType() {
    return this->type;
}

string Token::getValue() {
    return this->value;
}