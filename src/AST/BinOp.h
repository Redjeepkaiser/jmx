/**
 * Header comment TODO
 * @author Jakob Kaiser
 */

#ifndef JMX_BINOP_H
#define JMX_BINOP_H

#include "Token.h"
#include "Node.h"

class BinOp: public Node {
public:
    BinOp(Node &left, Token op, Node &right);
    NodeType getType();

private:
    Node *left;
    Token token;
    Node *right;
};

#endif // JMX_BINOP_H
