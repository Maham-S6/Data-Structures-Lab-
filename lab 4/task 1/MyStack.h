// MyStack.h
#pragma once
#include "Stack.h"
#include <iostream>

class MyStack : public Stack
{
public:
    // Fixed parameter name from _currentIndex to _maxCapacity so it matches the base class logic
    MyStack(int _maxCapacity = 0) : Stack(_maxCapacity) {};
    MyStack(const MyStack& ma) : Stack(ma) {};

    // Moved these declarations inside the class
    void push(int v);
    bool pop(int& v);
};

void MyStack::push(int v)
{
    if (!isFull())
    {
        // Moved the logic INSIDE the if-statement block
        values[++currentIndex] = v;
        return;
    }
    std::cout << "Array is full\n";
}

bool MyStack::pop(int& v)
{
    if (!isEmpty())
    {
        v = values[currentIndex--];
        return true;
    }
    return false;
}