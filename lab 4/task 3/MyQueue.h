#pragma once
#include<iostream>
#include "Queue.h"
using namespace std; 
class MyQueue : public Queue {
private:
    int* values;

public:
    MyQueue(int s) : Queue(s) {
        if (s > 0) values = new int[s] { 0 };
        else values = nullptr;
    }

    ~MyQueue() {
        if (values != nullptr) delete[] values;
    }

    void enqueue(const int& value) override {
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
    }

    int dequeue() override {
        if (!isEmpty()) {
            int val = values[startOfQIndex];
            if (count == 1) {
                startOfQIndex = -1;
                topOfQIndex = -1;
            }
            else {
                startOfQIndex = (startOfQIndex + 1) % maxCapacity;
            }
            count--;
            return val;
        }
        return -1;
    }

    void display(std::ostream& out) const override {
        if (isEmpty()) return;
        int index = startOfQIndex;
        for (int i = 0; i < count; i++) {
            out << values[index] << " ";
            index = (index + 1) % maxCapacity;
        }
    }
};

