#include "InfixToPostfix.h"
//#include "Calculator.h"

#include <iostream>
#include <string>
//#include 'cmake-build-debug/Calculator.h'
#include "Calculator.h"

int main() {
    Calculator calculator;


    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infixExpression);



    std::string postfixExpression = infixToPostfix(infixExpression);
    if (!postfixExpression.empty()) {
        std::cout << "Postfix expression: " << postfixExpression << std::endl;

        int result = calculator.evaluate(postfixExpression);
        std::cout << "Result: " << result << std::endl;
//        if (result != 0) {
//            std::cout << "Result: " << result << std::endl;
//        }

    }
    return 0;
}