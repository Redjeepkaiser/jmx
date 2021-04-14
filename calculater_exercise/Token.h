/**
 * This file defines the token class and its associated functions.
 * @author Jakob Kaiser
 */
#ifndef JMX_TOKEN_H
#define JMX_TOKEN_H

#include<string>
using namespace std;

// Different token classes
enum TokenType{INTEGER, PLUS, MINUS, EOL};

/**
 * Token class containing a type and value.
 */
class Token {
    private:
        TokenType type;
        string value;

    public:
        Token(TokenType type, string value);
        TokenType getType();
        string getValue();
};

#endif //JMX_TOKEN_H
