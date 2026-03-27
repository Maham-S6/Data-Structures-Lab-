// MyQueue.h
#pragma once
#include "Queue.h"
#include <iostream>
using namespace std;
class MyQueue : public Queue
{
protected:
    int* values; // Added missing pointer array declaration

public:
    MyQueue(int s) : Queue(s)
    {
        if (s != 0)
        {
            values = new int[maxCapacity] {0};
        }
        else
        {
            values = nullptr;
        }
    }

    MyQueue(const MyQueue& mq) : Queue(mq)
    {
        // Fixed the broken bitwise OR (|) to a logical AND (&&) check
        if (maxCapacity != 0 && mq.values != nullptr)
        {
            values = new int[maxCapacity] {0};
            for (int i = 0; i < maxCapacity; i++)
            {
                values[i] = mq.values[i];
            }
        }
        else
        {
            values = nullptr;
        }
    }

    ~MyQueue()
    {
        if (values != nullptr)
        {
            delete[] values; // Fixed broken delete statement
            values = nullptr;
        }
    }

    void enqueue(const int& value);
    int dequeue();
    void display(std::ostream& out) const;
};

// Implemented missing functions cut off by the PDF formatting
void MyQueue::enqueue(const int& value)
{
    if (!isFull()) {
        if (isEmpty()) {
            startOfQIndex = 0;
            topOfQIndex = 0;
        }
        else {
            topOfQIndex = (topOfQIndex + 1) % maxCapacity;
        }
        values[topOfQIndex] = value;
        count++;
    }
    else {
        std::cout << "Queue is full\n";
    }
}

int MyQueue::dequeue()
{
    if (!isEmpty()) {
        int val = values[startOfQIndex];
        if (startOfQIndex == topOfQIndex) {
            // Queue is now empty, reset indices
            startOfQIndex = -1;
            topOfQIndex = -1;
        }
        else {
            startOfQIndex = (startOfQIndex + 1) % maxCapacity;
        }
        count--;
        return val;
    }
    std::cout << "Queue is empty\n";
    return -1;
}

void MyQueue::display(std::ostream& out) const
{
    if (isEmpty()) return;
    int i = startOfQIndex;
    for (int c = 0; c < count; c++) {
        out << values[i] << " ";
        i = (i + 1) % maxCapacity;
    }
}