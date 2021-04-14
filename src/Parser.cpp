#include "Parser.h"
#include "Errors.h"

Token Parser::getToken() {
    char currentCharacter;
    this->is->get(currentCharacter);

    while (currentCharacter) {
        if (isspace(currentCharacter)) {
            this->is->get(currentCharacter);
        } else if (isdigit(currentCharacter)) {
            string value;
            value = currentCharacter;
            return Token(INTEGER, value);
        } else if (currentCharacter == 43) {
            return Token(PLUS);
        } else if (currentCharacter == 45) {
            return Token(MINUS);
        }
    }

    return Token(END);
}

Parser::Parser(istream *is) {
    this->is = is;
}

Token Parser::eat(TokenType type) {
    Token currentToken = getToken();

    if (currentToken.getType() !=  type) {
        throw SytaxError();
    }

    return currentToken;
}