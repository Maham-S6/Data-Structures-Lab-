#pragma once
#include<iostream>
using namespace std; 

class Stack {
public:
    Stack(int _maxCapacity = 0);
    Stack(const Stack& s);
    virtual void push(int v) = 0;
    virtual bool pop(int& value) = 0;
    bool isEmpty();
    bool isFull();
    virtual ~Stack() {
        if (values != nullptr) {
            delete[] values;
        }
    }

protected:
    int currentIndex;
    int* values;
    int maxCapacity;
};

Stack::Stack(int _maxCapacity) {
    currentIndex = -1;
    maxCapacity = _maxCapacity;
    if (maxCapacity > 0) {
        values = new int[maxCapacity] { 0 };
    }
    else {
        values = nullptr;
    }
}

Stack::Stack(const Stack& s) {
    currentIndex = s.currentIndex;
    maxCapacity = s.maxCapacity;
    if (maxCapacity > 0) {
        values = new int[maxCapacity];
        for (int i = 0; i <= currentIndex; i++) {
            values[i] = s.values[i];
        }
    }
    else {
        values = nullptr;
    }
}

bool Stack::isEmpty() {
    return (currentIndex < 0);
}

bool Stack::isFull() {
    return (currentIndex == maxCapacity - 1);
}


