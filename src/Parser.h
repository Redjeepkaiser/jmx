#ifndef JMX_PARSER_H
#define JMX_PARSER_H

#include<iostream>
#include "Token.h"

using namespace std;

/**
 * Parser class that generates tokens from input stream.
 * @author Jakob Kaiser
 */
class Parser {
private:
    istream *is;

    /**
     * Reads from input stream and generates token from it.
     * @return generated token.
     */
    Token getToken();

public:
    /**
     * Parser constructor.
     * @param os stream from which to read.
     */
    Parser(istream *is);

    /**
     * Eats a token with given type from input stream. If token type does not
     * match with given type a syntax error is thrown.
     * @param type tokentype to eat
     * @return eaten token
     */
    Token eat(TokenType type);
};

#endif //JMX_PARSER_H
