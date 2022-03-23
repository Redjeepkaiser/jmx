/**
 * This file provides tests to test the functionality of the Num class.
 *
 * @author Jakob Kaiser
 */

#include <gtest/gtest.h>
#include "../src/AST/Num.h"

TEST(NumTest, CONSTRUCTOR) {
  Num n = Num("INTEGER", 4);
}
