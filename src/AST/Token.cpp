#include "Token.h"

Token::Token(TokenType type, string value) {
    type = type;
    value = value;
}

Token::Token(TokenType type) {
    type = type;
    value = "";
}

TokenType Token::getType() {
    return type;
}

string Token::getValue() {
    return value;
}
