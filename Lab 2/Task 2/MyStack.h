#pragma once
#include "Stack.h"

class MyStack : public stack {
public:
    // Constructor passes size to parent Stack class [cite: 149]
    MyStack(int _size = 0) : stack(_size) {};
    MyStack(const MyStack& ma) : stack(ma) {};

    void push(int v) override {
        if (!isFull()) {
            values[++currentIndex] = v; // [cite: 160]
        }
        else {
            cout << "Array is full\n"; // [cite: 162]
        }
    }

    bool pop(int& v) override {
        if (!isEmpty()) {
            v = values[currentIndex--]; // [cite: 167]
            return true;
        }
        return false;
    }
};