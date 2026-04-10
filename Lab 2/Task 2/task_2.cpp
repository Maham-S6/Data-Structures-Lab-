#include <iostream>
#include "stack.h"
#include "MyStack.h"

using namespace std;

const int MAX_SIZE = 10;

// Global functions 
    void read(stack * s, istream & in, int n)
    {
        int val;
        for (int i = 0; i < n && !s->isFull(); i++) {
            in >> val;
            s->push(val);
        }
    }

    void display(stack * s, ostream & out) {
        MyStack temp(MAX_SIZE);
        int val;
        while (s->pop(val)) {
            out << val << " ";
            temp.push(val);
        }
        while (temp.pop(val)) {
            s->push(val);
        }
        out << endl;
    }

    void copy(stack * src, stack * dst) {
        MyStack temp(MAX_SIZE);
        int val;
        while (src->pop(val)) {
            temp.push(val);
        }
        while (temp.pop(val)) {
            src->push(val);
            dst->push(val);
        }
    }

    void stats(stack * s, int& max, float& average) {
        MyStack temp(MAX_SIZE);
        int val, sum = 0, count = 0;
        max = -999999;
        while (s->pop(val)) {
            if (val > max) max = val;
            sum += val;
            count++;
            temp.push(val);
        }
        while (temp.pop(val)) {
            s->push(val);
        }
        if (count > 0) average = (float)sum / count;
    }

    int main() {
        // MAX_SIZE defined at the top [cite: 248]
        stack* A = new MyStack(MAX_SIZE);
        int n = 0;

        cout << "Please select a number between 1 and " << MAX_SIZE << ": ";
        cin >> n;

        read(A, cin, n);
        cout << "Stack A Values: ";
        display(A, cout);

        stack* B = new MyStack(MAX_SIZE);
        copy(A, B);
        cout << "Stack B Values: ";
        display(B, cout);

        int mx = 0;
        float ag = 0.0;
        stats(A, mx, ag);

        cout << "Average is " << ag << " maximum is " << mx << endl; // [cite: 278-280]

        delete A;
        delete B;
        return 0;
    }
  