#pragma once
#include "Stack.h"
#include <iostream>
using namespace std; 

class MyStack : public Stack {
public:
    MyStack(int _maxCapacity = 0) : Stack(_maxCapacity) {}
    MyStack(const MyStack& s) : Stack(s) {}

    void push(int v) override {
        if (!isFull()) {
            values[++currentIndex] = v;
        }
        else {
            std::cout << "Stack Overflow\n";
        }
    }

    bool pop(int& v) override {
        if (!isEmpty()) {
            v = values[currentIndex--];
            return true;
        }
        return false;
    }
};


