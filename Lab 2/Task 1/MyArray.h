#pragma once
#include<iostream>
#include"AbstractArray.h"
class MyArray : public AbstractArray
{
public:
    MyArray(int _maxCapacity = 0) : AbstractArray(_maxCapacity) {}
    MyArray(const MyArray& ma) : AbstractArray(ma) {}

    void add(int v)
    {
        if (!isFull())
            values[++currentIndex] = v;
        else
            cout << "Array is full\n";
    }

    bool remove(int& v)
    {
        if (!isEmpty())
        {
            v = values[currentIndex];
            currentIndex--;
            return true;
        }
        return false;
    }

    bool get(int index, int& v)
    {
        if (index >= 0 && index <= currentIndex)
        {
            v = values[index];
            return true;
        }
        return false;
    }

    void insert(int index, int value)
    {
        if (index >= 0 && index <= currentIndex)
            values[index] = value;
        else
            cout << index << " is invalid\n";
    }
};

void read(MyArray& A, istream& in, int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        in >> x;
        A.add(x);
    }
}

void display(MyArray& A, ostream& out)
{
    int x;
    for (int i = 0; i < A.size(); i++)
    {
        A.get(i, x);
        out << x << " ";
    }
    out << endl;
}

void copy(MyArray& src, MyArray& dst)
{
    int x;
    for (int i = 0; i < src.size(); i++)
    {
        src.get(i, x);
        dst.add(x);
    }
}

void insert(MyArray& src, MyArray& dst, int pos)
{
    int x;

    for (int i = 0; i < src.size(); i++)
    {
        src.get(i, x);

        if (pos + i < dst.size())
            dst.insert(pos + i, x);
        else
            dst.add(x);
    }
}

void shiftLeft(MyArray& A, int pos)
{
    int x;

    if (pos < 0 || pos >= A.size())
        return;

    for (int i = pos; i < A.size() - 1; i++)
    {
        A.get(i + 1, x);
        A.insert(i, x);
    }

    A.remove(x);
}

void shiftRight(MyArray& A, int pos)
{
    int x;

    if (A.isFull() || pos < 0 || pos > A.size())
        return;

    A.add(0);

    for (int i = A.size() - 1; i > pos; i--)
    {
        A.get(i - 1, x);
        A.insert(i, x);
    }

    A.insert(pos, 0);
}

void stats(MyArray& A, int& max, float& average)
{
    int x;
    int sum = 0;

    if (A.isEmpty())
    {
        max = 0;
        average = 0;
        return;
    }

    A.get(0, max);

    for (int i = 0; i < A.size(); i++)
    {
        A.get(i, x);
        sum = sum + x;

        if (x > max)
            max = x;
    }

    average = (float)sum / A.size();
}
