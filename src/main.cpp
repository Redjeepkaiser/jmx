/**
 * This file provides the entry point to the interpreter.
 *
 * @author Jakob Kaiser
 */

#include "Interpreter.h"

using namespace std;

int main() {
    string input = "3+52";

    Interpreter interpreter = Interpreter();
    interpreter.feed(input);
    cout << interpreter.interpret();
    return 0;
}
