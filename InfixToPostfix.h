
#ifndef LASTLAB_INFIXTOPOSTFIX_H
#define LASTLAB_INFIXTOPOSTFIX_H
#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

#include "Stack.h"
#include "Queue.h"
#include <string>

bool isOperator(char ch);

int getPrecedence(char op);

std::string infixToPostfix(const std::string& infixExpression);

#endif  // INFIX_TO_POSTFIX_H

#endif //LASTLAB_INFIXTOPOSTFIX_H
