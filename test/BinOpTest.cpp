/**
 * This file provides tests to test the functionality of the BinOp class.
 *
 * @author Jakob Kaiser
 */

#include <gtest/gtest.h>
#include "../src/AST/Num.h"
#include "../src/AST/BinOp.h"

TEST(BinOpTest, Constructor) {
  Token t = Token(MUL, "*");
  Num n1 = Num("INTEGER", 4);
  Num n2 = Num("INTEGER", 4);
  BinOp bo = BinOp(n1, t, n2);
}
