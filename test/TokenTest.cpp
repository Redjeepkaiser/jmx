#include <gtest/gtest.h>
#include "../src/Token.h"

TEST(TokenTest, ConstructorTestInteger) {
    Token t(INTEGER, "3");
    ASSERT_EQ(t.getType(), INTEGER);
    ASSERT_EQ(t.getValue(), "3");
}
