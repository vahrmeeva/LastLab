cmake_minimum_required(VERSION 3.23)
project(LastLab)

set(CMAKE_CXX_STANDARD 14)

add_executable(LastLab main.cpp Node.cpp Node.h Calculator.cpp Calculator.h Stack.cpp Stack.h LinkedList.cpp LinkedList.h Queue.cpp Queue.h InfixToPostfix.cpp InfixToPostfix.h)
