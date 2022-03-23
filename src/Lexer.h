/**
 * This file defines the interpreter class and associated functions.
 *
 * @author Jakob Kaiser
 */

#ifndef JMX_LEXER_H
#define JMX_LEXER_H

#include<iostream>
#include "AST/Token.h"

using namespace std;

/**
 * Lexer class that generates tokens from input string.
 * @author Jakob Kaiser
 */
class Lexer {
private:
    /**
     * Lexer input string.
     */
    string input;

    /**
     * Current position in the input string.
     */
    int current_position;

    /**
     * Current character at the current position of the input string.
     */
    char current_character;

    /**
     * Skips whitespace and adjust current position and current character
     * accordingly.
     */
    void skipWhitespace();

    /**
     * Gets an integer token from inputs string.
     * @return integer token
     */
    Token getIntegerToken();

    /**
     * Advances position in the input string by one.
     */
    void advance();

public:
    /**
     * Default lexer constructor.
     */
    Lexer() {};

    /**
     * Feeds the lexer an input string.
     * @param input
     */
    void feed(string input);

    /**
     * Reads from input and generates the next token from it.
     * @return generated token.
     */
    Token getNextToken();
};

#endif //JMX_LEXER_H
