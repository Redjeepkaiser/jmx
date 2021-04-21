/**
 * This file provides tests to test the functionality of the lexer class.
 *
 * @author Jakob Kaiser
 */

#include <gtest/gtest.h>
#include "../src/Interpreter.h"

TEST(LexerTest, BasicAddition) {
    string input = "3+52";
    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    ASSERT_EQ(interpreter.interpret(), 55);
}

TEST(LexerTest, BasicSubtraction) {
    string input = "43-7";
    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    ASSERT_EQ(interpreter.interpret(), 36);
}

TEST(LexerTest, BasicAdditionAndSubtraction) {
    string input = "43-7+5";
    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    ASSERT_EQ(interpreter.interpret(), 41);
}