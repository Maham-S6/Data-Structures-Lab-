#pragma once
#include <iostream>
using namespace std;

class stack {
public:
    stack(int _maxCapacity = 0);
    stack(const stack& AA);
    virtual void push(int v) = 0; // [cite: 118]
    virtual bool pop(int& value) = 0; // [cite: 119]
    bool isEmpty(); // [cite: 120]
    bool isFull(); // [cite: 121]
protected:
    int currentIndex; // [cite: 124]
    int* values; // [cite: 125]
    int maxCapacity; // [cite: 126]
};

// Implementations [cite: 127-144]
inline stack::stack(int _maxCapacity) {
    currentIndex = -1;
    maxCapacity = _maxCapacity;
    values = new int[maxCapacity] {0};
}

inline bool stack::isEmpty() {
    return (currentIndex < 0);
}

inline bool stack::isFull() {
    return (currentIndex == maxCapacity - 1);
}

