#include "BinOp.h"

BinOp::BinOp(Node &left, Token op, Node &right) {
  left = left;
  token = op;
  right = right;
}

NodeType BinOp::getType() {
  return BINOP;
}
