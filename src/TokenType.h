/**
 * This header file defines different token classes.
 *
 * @author Jakob Kaiser
 */

#ifndef MY_PROJECT_TOKENTYPE_H
#define MY_PROJECT_TOKENTYPE_H

/**
 * Enumeration of different token classes.
 *
 * INTEGER is a token containing integer values.
 *
 * PLUS is a token representing plus sign.
 *
 * MINUS is a token representing minus sign.
 *
 * MUL is a token representing a multiplying sign.
 *
 * DIV is a token representing a dividing sign.
 *
 * LPAREN is a token representing a left parentheses.
 *
 * RPAREN is a token representing a right parentheses.
 *
 * END is a token representing end of input.
 */
enum TokenType {
    INTEGER,
    PLUS,
    MINUS,
    MUL,
    DIV,
    LPAREN,
    RPAREN,
    END
};

#endif //MY_PROJECT_TOKENTYPE_H
