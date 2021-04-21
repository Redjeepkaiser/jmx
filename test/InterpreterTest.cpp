/**
 * This file provides tests to test the functionality of the lexer class.
 *
 * @author Jakob Kaiser
 */

#include <gtest/gtest.h>
#include "../src/Interpreter.h"

TEST(InterpreterTest, BasicAddition) {
    string input = "3+52";
    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    ASSERT_EQ(interpreter.interpret(), 55);
}

TEST(InterpreterTest, BasicSubtraction) {
    string input = "43-7";
    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    ASSERT_EQ(interpreter.interpret(), 36);
}

TEST(InterpreterTest, BasicAdditionAndSubtraction) {
    string input = "43-7+5";
    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    ASSERT_EQ(interpreter.interpret(), 41);
}

TEST(InterpreterTest, BasicSyntaxError) {
    string input = "-";
    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    ASSERT_DEATH(interpreter.interpret(), "Syntax Error");
}

TEST(InterpreterTest, BasicMultiplication) {
    string input = "3*5";
    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    ASSERT_EQ(interpreter.interpret(), 15);
}

TEST(InterpreterTest, BasicDivision) {
    string input = "16/4";
    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    ASSERT_EQ(interpreter.interpret(), 4);
}

TEST(InterpreterTest, BasicPrecedence) {
    string input = "3+16/4";
    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    ASSERT_EQ(interpreter.interpret(), 7);

    input = "3*16/4";
    interpreter.feed(input);
    ASSERT_EQ(interpreter.interpret(), 12);
}