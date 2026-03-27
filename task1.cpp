#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"

/* MANDATORY STEPS FOR TASK 1

1. Understanding the task:
I need to write several basic utility functions for a Queue (a line of items). I am strictly restricted to using only Queues to solve these problems, unless a Stack (a pile) is absolutely necessary. The tasks involve reading inputs, displaying the line, joining two lines together, joining them in reverse, finding the total number of items, calculating basic statistics (maximum and average), and checking if two lines are exactly identical.

2. Solution description:
Since a Queue only lets me take from the front and add to the back, I will use temporary Queues to hold items while I process them.
For example, to count the items (getSize), I will take each item from the front of the main line, count it, and place it into a temporary line. Once empty, I will move everything back to the original line.
Progression for reverse append:
Line (A -> B -> C ->) moves into a Stack.
Stack gives back C, then B, then A into the new Line (C -> B -> A ->). This is why a Stack is justified here; a Queue cannot reverse order by itself.

3. Reusing functions:
I will reuse the basic enqueue (add) and dequeue (remove) functions provided in the header files. For the 'isEqual' function, I will first reuse the 'getSize' function to quickly check if the lines even have the same number of items before checking them one by one.

4. Learning from the task:
I learnt how to manipulate data when my access is artificially restricted. It forces you to think about how to restore the original state of the data after you finish reading it.

5. Skills developed:
I have developed better logical problem-solving skills, specifically regarding temporary buffers. I can now write programmes that handle sequential data, like a printer queue or a customer ticketing system.
*/

// Function prototypes
void read(Queue* q, istream& in);
void display(Queue* q, ostream& out);
void append(Queue* src, Queue* dst);
void append(Queue* src, Queue* dst, int no);
void reverseAppend(Queue* src, Queue* dst);
int getSize(Queue* q);
void stats(Queue* q, int& mx, float& average);
bool isEqual(Queue* q1, Queue* q2);

const int MAX_SIZE = 5;

// --- Function Implementations ---

void read(Queue* q, istream& in) {
    int val;
    while (!q->isFull()) {
        in >> val;
        q->enqueue(val);
    }
}

void display(Queue* q, ostream& out) {
    Queue* temp = new MyQueue(MAX_SIZE);
    int val;
    while (!q->isEmpty()) {
        val = q->dequeue();
        out << val << " ";
        temp->enqueue(val);
    }
    out << endl;

    // Restore the original queue
    while (!temp->isEmpty()) {
        q->enqueue(temp->dequeue());
    }
    delete temp;
}

void append(Queue* src, Queue* dst) {
    Queue* temp = new MyQueue(MAX_SIZE);
    int val;
    while (!src->isEmpty() && !dst->isFull()) {
        val = src->dequeue();
        dst->enqueue(val);
        temp->enqueue(val);
    }

    // Restore the source queue
    while (!temp->isEmpty()) {
        src->enqueue(temp->dequeue());
    }
    delete temp;
}

void append(Queue* src, Queue* dst, int no) {
    Queue* temp = new MyQueue(MAX_SIZE);
    int val;
    int count = 0;
    while (!src->isEmpty() && !dst->isFull() && count < no) {
        val = src->dequeue();
        dst->enqueue(val);
        temp->enqueue(val);
        count++;
    }

    // Move the rest of src into temp to keep the order intact
    while (!src->isEmpty()) {
        temp->enqueue(src->dequeue());
    }

    // Restore src
    while (!temp->isEmpty()) {
        src->enqueue(temp->dequeue());
    }
    delete temp;
}

void reverseAppend(Queue* src, Queue* dst) {
    // Justification: A Stack is needed here because reversing the order of elements 
    // requires Last-In-First-Out (LIFO) behaviour, which a Queue cannot provide.
    Stack* pile = new MyStack(MAX_SIZE);
    Queue* temp = new MyQueue(MAX_SIZE);
    int val;

    while (!src->isEmpty()) {
        val = src->dequeue();
        pile->push(val);
        temp->enqueue(val);
    }

    while (!pile->isEmpty() && !dst->isFull()) {
        pile->pop(val);
        dst->enqueue(val);
    }

    while (!temp->isEmpty()) {
        src->enqueue(temp->dequeue());
    }
    delete pile;
    delete temp;
}

int getSize(Queue* q) {
    Queue* temp = new MyQueue(MAX_SIZE);
    int count = 0;
    while (!q->isEmpty()) {
        temp->enqueue(q->dequeue());
        count++;
    }
    while (!temp->isEmpty()) {
        q->enqueue(temp->dequeue());
    }
    delete temp;
    return count;
}

void stats(Queue* q, int& mx, float& average) {
    Queue* temp = new MyQueue(MAX_SIZE);
    int count = 0;
    int sum = 0;
    mx = -999999;
    int val;

    while (!q->isEmpty()) {
        val = q->dequeue();
        if (val > mx) {
            mx = val;
        }
        sum += val;
        count++;
        temp->enqueue(val);
    }

    if (count > 0) {
        average = (float)sum / count;
    }
    else {
        average = 0.0;
    }

    while (!temp->isEmpty()) {
        q->enqueue(temp->dequeue());
    }
    delete temp;
}

bool isEqual(Queue* q1, Queue* q2) {
    if (getSize(q1) != getSize(q2)) {
        return false;
    }

    Queue* temp1 = new MyQueue(MAX_SIZE);
    Queue* temp2 = new MyQueue(MAX_SIZE);
    bool equal = true;
    int v1, v2;

    while (!q1->isEmpty() && !q2->isEmpty()) {
        v1 = q1->dequeue();
        v2 = q2->dequeue();

        if (v1 != v2) equal = false;

        temp1->enqueue(v1);
        temp2->enqueue(v2);
    }

    while (!temp1->isEmpty()) q1->enqueue(temp1->dequeue());
    while (!temp2->isEmpty()) q2->enqueue(temp2->dequeue());

    delete temp1;
    delete temp2;
    return equal;
}

int main() {
    Queue* A = new MyQueue(MAX_SIZE);
    int n = 0;
    read(A, cin);
    cout << "Queue A Values: ";
    display(A, cout);

    Queue* B = new MyQueue(MAX_SIZE);
    append(A, B);
    cout << "Queue B Values: ";
    display(B, cout);

    Queue* C = new MyQueue(MAX_SIZE);
    C->enqueue(9);
    C->enqueue(7);
    C->enqueue(5);
    append(A, C, 2);
    cout << "Queue C Values after append of 2 values from A: ";
    display(C, cout);

    Queue* D = new MyQueue(MAX_SIZE);
    reverseAppend(C, D);
    cout << "Queue D Values after reverse append from C: ";
    display(D, cout);

    int mx = 0;
    float ag = 0.0;
    stats(A, mx, ag);
    cout << "Queue A Values: ";
    display(A, cout);
    cout << "Average is " << ag << " maximum is " << mx << endl;

    Queue* M = new MyQueue(MAX_SIZE);
    Queue* N = new MyQueue(MAX_SIZE);
    Queue* P = new MyQueue(MAX_SIZE);
    append(A, M);
    append(N, M);
    append(N, P);
    P->enqueue(111);

    if (!isEqual(A, M)) {
        cout << "Not Equal:\n";
    }
    else {
        cout << "Equal:\n";
    }

    if (!isEqual(A, P)) {
        cout << "Not Equal:\n";
    }
    else {
        cout << "Equal:\n";
    }

    return 0;
}