#include <gtest/gtest.h>
#include <fstream>
#include "../src/Parser.h"

TEST(ParserTest, ConstructorTest) {
    ifstream input;
    input.open("parserInputFile.txt", ifstream::in);
    Parser p(&input);
    Token t;
    t = p.eat(PLUS);
    ASSERT_EQ(t.getType(), PLUS);
}
