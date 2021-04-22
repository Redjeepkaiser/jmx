/**
 * This file provides tests to test the functionality of the lexer class.
 *
 * @author Jakob Kaiser
 */

#include <gtest/gtest.h>
#include "../src/Lexer.h"

TEST(LexerTest, SkipWhiteSpace) {
    Lexer l = Lexer();
    string input = "3 3";
    l.feed(input);

    Token test1 = l.getNextToken();
    ASSERT_EQ(test1.getType(), INTEGER);
    ASSERT_EQ(test1.getValue(), "3");
    Token test2 = l.getNextToken();
    ASSERT_EQ(test2.getType(), INTEGER);
    ASSERT_EQ(test2.getValue(), "3");
    Token test3 = l.getNextToken();
    ASSERT_EQ(test3.getType(), END);;
}

TEST(LexerTest, LongerIntegers) {
    Lexer l = Lexer();
    string input = "33134525656";
    l.feed(input);

    Token test1 = l.getNextToken();
    ASSERT_EQ(test1.getType(), INTEGER);
    ASSERT_EQ(test1.getValue(), "33134525656");
    Token test2 = l.getNextToken();
    ASSERT_EQ(test2.getType(), END);;
}

TEST(LexerTest, Plus) {
    Lexer l = Lexer();
    string input = "3+52";
    l.feed(input);

    Token test1 = l.getNextToken();
    ASSERT_EQ(test1.getType(), INTEGER);
    ASSERT_EQ(test1.getValue(), "3");
    Token test2 = l.getNextToken();
    ASSERT_EQ(test2.getType(), PLUS);
    Token test3 = l.getNextToken();
    ASSERT_EQ(test3.getType(), INTEGER);
    ASSERT_EQ(test3.getValue(), "52");
    Token test4 = l.getNextToken();
    ASSERT_EQ(test4.getType(), END);;
}

TEST(LexerTest, Minus) {
    Lexer l = Lexer();
    string input = "60-2";
    l.feed(input);

    Token test1 = l.getNextToken();
    ASSERT_EQ(test1.getType(), INTEGER);
    ASSERT_EQ(test1.getValue(), "60");
    Token test2 = l.getNextToken();
    ASSERT_EQ(test2.getType(), MINUS);
    Token test3 = l.getNextToken();
    ASSERT_EQ(test3.getType(), INTEGER);
    ASSERT_EQ(test3.getValue(), "2");
    Token test4 = l.getNextToken();
    ASSERT_EQ(test4.getType(), END);;
}
