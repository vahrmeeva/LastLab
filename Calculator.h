#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include "Stack.h"

class Calculator {
public:
    int evaluate(const std::string& postfixExpression);
};

#endif