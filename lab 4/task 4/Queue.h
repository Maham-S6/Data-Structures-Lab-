#pragma once
#include <iostream>
using namespace std; 

class Queue {
public:
    Queue(int cap) : startOfQIndex(-1), topOfQIndex(-1), maxCapacity(cap), count(0) {}
    virtual ~Queue() {}

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == maxCapacity; }

    virtual void enqueue(const int& value) = 0;
    virtual int dequeue() = 0;
    virtual void display(std::ostream& out) const = 0;

protected:
    int startOfQIndex;
    int topOfQIndex;
    int maxCapacity;
    int count;
};


