// Stack.h
#pragma once
#include<iostream>
using namespace std;
class Stack
{
public:
    // Fixed typo: int_maxCapacity is now int _maxCapacity
    Stack(int _maxCapacity = 0);
    Stack(const Stack& AA);
    virtual void push(int v) = 0;
    virtual bool pop(int& value) = 0;
    bool isEmpty();
    bool isFull();
    virtual ~Stack() {} // Added virtual destructor for safe inheritance

protected:
    // Moved these variables INSIDE the class definition (PDF had them outside)
    int currentIndex;
    int* values;
    int maxCapacity;
};

Stack::Stack(int _maxCapacity)
{
    // Moved logic inside the constructor body
    currentIndex = -1;
    maxCapacity = _maxCapacity;
    if (maxCapacity > 0) {
        values = new int[maxCapacity] {0};
    }
    else {
        values = nullptr;
    }
}

Stack::Stack(const Stack& s)
{
    currentIndex = s.currentIndex; // Corrected to copy current index
    maxCapacity = s.maxCapacity;
    if (maxCapacity > 0) {
        values = new int[maxCapacity] {0};
        for (int i = 0; i < maxCapacity; i++)
        {
            values[i] = s.values[i];
        }
    }
    else {
        values = nullptr;
    }
}

bool Stack::isEmpty()
{
    return (currentIndex < 0);
}

bool Stack::isFull()
{
    return (currentIndex == maxCapacity - 1);
}