// Queue.h
#pragma once
#include <iostream>

class Queue
{
public:
    Queue(int cap) : startOfQIndex(-1), topOfQIndex(-1), maxCapacity(cap), count(0) {}
    Queue(const Queue& q) : startOfQIndex(q.startOfQIndex), topOfQIndex(q.topOfQIndex), maxCapacity(q.maxCapacity), count(q.count) {}
    virtual ~Queue() {}

    bool isEmpty() const;
    bool isFull() const;
    virtual void enqueue(const int& value) = 0;
    virtual int dequeue() = 0;
    virtual void display(std::ostream&) const = 0;

protected:
    // Moved inside the class definition
    int startOfQIndex;
    int topOfQIndex;
    int maxCapacity;
    int count;
};

bool Queue::isEmpty() const
{
    return (count == 0);
}

bool Queue::isFull() const
{
    return (count == maxCapacity);
}