/**
 * This file provides the entry point to the interpreter.
 *
 * @author Jakob Kaiser
 */

#include "Interpreter.h"

using namespace std;

int main() {
    string input = "40/(20/10)";
    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    interpreter.interpret();
    return 0;
}
