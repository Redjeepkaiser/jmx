#include "Num.h"

Num::Num(std::string token, int value) {
  token = token;
  value = value;
}

NodeType Num::getType() {
  return NUM;
}
