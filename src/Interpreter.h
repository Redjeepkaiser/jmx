/**
 * This file defines the interpreter class and associated functions.
 *
 * @author Jakob Kaiser
 */

#ifndef JMX_INTERPRETER_H
#define JMX_INTERPRETER_H

#include "Lexer.h"

class Interpreter {
private:
    Lexer lexer;
    Token current_token;

    /**
     * Eats a token with given type from input string. If token type does not
     * match with given type a syntax error is thrown.
     * @param type tokentype to eat
     */
    void eat(TokenType type);

    /**
     * Eats an integer token and returns its value.
     * @return integer token value
     */
    int term();

public:
    /**
     * Default interpreter constructor.
     */
    Interpreter();

    /**
     * Feeds the interpreter an input string.
     * @param input
     */
    void feed(string input);

    /**
     * Interprets the given input string.
     * @return result of the expression
     */
    int interpret();
};

#endif //JMX_INTERPRETER_H
