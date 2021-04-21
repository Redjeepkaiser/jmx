/**
 * This file defines the interpreter class and associated functions.
 *
 * expr   : term ((PLUS | MINUS) term)*
 * term   : factor ((MUL | DIV) factor)*
 * factor : INTEGER
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
     * factor : INTEGER
     * @return integer token value
     */
    int factor();

    /**
     * term   : factor ((MUL | DIV) factor)*
     * @return integer token value
     */
    int term();

    /**
     * expr   : term ((PLUS | MINUS) term)*
     */
    int expr();

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
