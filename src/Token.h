#ifndef JMX_TOKEN_H
#define JMX_TOKEN_H

#include<string>
#include "TokenType.h"

using namespace std;

/**
 * Token class containing a token type and value.
 * @author Jakob Kaiser
 */
class Token {
private:
    TokenType type;
    string value;

public:
    /**
     * Token constructor for tokens containing values.
     * @param type token type
     * @param value token value
     */
    Token(TokenType type, string value);

    /**
    * Token constructor for tokens without values.
    * @param type token type
    */
    Token(TokenType type);

    /**
     * Default constructor.
     */
     Token(){};

    /**
     * Getter for token type.
     * @return toke type
     */
    TokenType getType();

    /**
     * Getter for toke value.
     * @return
     */
    string getValue();
};

#endif //JMX_TOKEN_H
