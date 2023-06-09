#include "InfixToPostfix.h"
#include <iostream>
#include <string>

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string infixToPostfix(const std::string& infixExpression) {
    std::string postfixExpression;
    Stack operatorStack;
    Queue outputQueue;

    if (infixExpression.empty()) {
        std::cout << "Empty expression!" << std::endl;
        return "";
    }

    // Проверка на наличие операторов в начале или конце выражения
    if (isOperator(infixExpression.front()) || isOperator(infixExpression.back())) {
        std::cout << "Invalid expression format!" << std::endl;
        return "";
    }

    for (char ch : infixExpression) {
        if (isspace(ch)) {
            continue;  // Пропустить пробелы
        } else if (isOperator(ch)) {
            while (!operatorStack.isEmpty() && operatorStack.top() != '(' && getPrecedence(operatorStack.top()) >= getPrecedence(ch)) {
                outputQueue.enqueue(operatorStack.pop());
            }
            operatorStack.push(ch);
        } else if (ch == '(') {
            operatorStack.push(ch);
        } else if (ch == ')') {
            while (!operatorStack.isEmpty() && operatorStack.top() != '(') {
                outputQueue.enqueue(operatorStack.pop());
            }
            if (operatorStack.isEmpty()) {
                std::cout << "Mismatched parentheses!" << std::endl;
                return "";
            }
            operatorStack.pop();  // Удаляем '(' из стека
        } else {
            // Операнд
            outputQueue.enqueue(ch);
        }
    }

    while (!operatorStack.isEmpty()) {
        if (operatorStack.top() == '(') {
            std::cout << "Missed parentheses!" << std::endl;
            return "";
        }
        outputQueue.enqueue(operatorStack.pop());
    }

    // Формируем постфиксное выражение из очереди
    while (!outputQueue.isEmpty()) {
        postfixExpression += outputQueue.dequeue();
    }

    return postfixExpression;
}
