#include <iostream>
using namespace std;

#define MAX_SIZE 10

class AbstractArray
{
protected:
    int currentIndex;
    int* values;
    int maxCapacity;

public:
    AbstractArray(int _maxCapacity = 0)
    {
        currentIndex = -1;
        maxCapacity = _maxCapacity;
        values = new int[maxCapacity] {0};
    }

    AbstractArray(const AbstractArray& AA)
    {
        currentIndex = AA.currentIndex;
        maxCapacity = AA.maxCapacity;
        values = new int[maxCapacity] {0};

        for (int i = 0; i <= currentIndex; i++)
            values[i] = AA.values[i];
    }

    virtual void add(int v) = 0;
    virtual bool remove(int& value) = 0;
    virtual bool get(int index, int& value) = 0;
    virtual void insert(int index, int value) = 0;

    bool isEmpty()
    {
        return currentIndex < 0;
    }

    bool isFull()
    {
        return currentIndex == maxCapacity - 1;
    }

    int size()
    {
        return currentIndex + 1;
    }
};