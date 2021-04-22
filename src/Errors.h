/**
 * This file defines custom errors.
 *
 * @author Jakob Kaiser
 */

#ifndef MY_PROJECT_ERRORS_H
#define MY_PROJECT_ERRORS_H

#include <exception>

using namespace std;

struct SytaxError : public exception {
public:
    const char * what () const throw () {
        return "Syntax Error";
    }
};
#endif //MY_PROJECT_ERRORS_H
