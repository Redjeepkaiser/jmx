/**
 * Header comment TODO
 * @author Jakob Kaiser
 */

#ifndef JMX_NUM_H
#define JMX_NUM_H

#include <string>
#include "Node.h"

class Num: public Node {
  public:
    Num(std::string token, int value);
    NodeType getType();

  private:
    std::string token;
    int value;
};

#endif //JMX_NUM_H
