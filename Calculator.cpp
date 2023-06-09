#include "Calculator.h"
#include "InfixToPostfix.h"
#include <iostream>



int Calculator::evaluate(const std::string& expression) {
    Stack stack;

    for (char c : expression) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else if (isOperator(c)) {
            if (stack.isEmpty()) {
                std::cout << "Invalid expression!" << std::endl;
                return 0;
            }

            int operand2 = stack.pop();

            if (stack.isEmpty()) {
                std::cout << "Invalid expression!" << std::endl;
                return 0;
            }

            int operand1 = stack.pop();

            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        std::cout << "Error: Division by zero!" << std::endl;
                        return 0;
                    }
                    break;
                default:
                    std::cout << "Invalid operation!" << std::endl;
                    return 0;
            }

            stack.push(result);
        } else {
            // Неправильный знак
            std::cout << "Invalid character: " << c << std::endl;
            return 0;
        }
    }

    if (stack.isEmpty()) {
        std::cout << "Invalid expression!" << std::endl;
        return 0;
    }

    return stack.pop();
}
