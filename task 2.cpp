#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"

/* MANDATORY STEPS FOR TASK 2

1. Understanding the task:
Following on from Task 1, I now need to implement functions that modify the order and contents of a Queue at specific positions. I need to be able to insert an entire line (or a single item) into another line at a given spot, and I need to shift items left or right from a specific point.

2. Solution description:
To insert an item at a specific position, I will use a temporary Queue. I will pull items from the main line and place them in the temporary one. I will use a counter, and when my counter reaches the target position, I will insert the new item into the temporary line first, and then continue moving the rest of the original items behind it.
For shifting:
- shiftRight from a position means rotating that specific section so the last item of the queue comes to that position.
- shiftLeft from a position means taking the item at that position and throwing it all the way to the back of the queue.

3. Reusing functions:
I will reuse the 'getSize' function from Task 1 to ensure positions are valid before attempting to insert or shift. I will also reuse the standard 'display' to test the outputs.

4. Learning from the task:
I have learnt how to manipulate the internal sequence of a Queue. Even though a Queue naturally only allows changes at the ends, you can simulate random-access insertions by unpacking and repacking the entire structure.

5. Skills developed:
I have developed the ability to carefully track indices and counters while data is in motion between different containers. This is highly useful for managing memory buffers or simulating operating system task scheduling.
*/

// Function prototypes (Reusing relevant ones from Task 1)
void display(Queue* q, ostream& out);
void append(Queue* src, Queue* dst);
void append(Queue* src, Queue* dst, int no);
void reverseAppend(Queue* src, Queue* dst);
int getSize(Queue* q);
bool isEqual(Queue* q1, Queue* q2);

// New Task 2 prototypes
void insert(Queue* src, Queue* dst, int pos);
void insert(Queue* q, int v, int pos);
void shiftRight(Queue* q, int pos);
void shiftLeft(Queue* q, int pos);

const int MAX_SIZE = 10;

// --- Task 1 Reused Implementations ---
void display(Queue* q, ostream& out) {
    Queue* temp = new MyQueue(MAX_SIZE);
    int val;
    while (!q->isEmpty()) {
        val = q->dequeue();
        out << val << " ";
        temp->enqueue(val);
    }
    out << endl;
    while (!temp->isEmpty()) q->enqueue(temp->dequeue());
    delete temp;
}

int getSize(Queue* q) {
    Queue* temp = new MyQueue(MAX_SIZE);
    int count = 0;
    while (!q->isEmpty()) {
        temp->enqueue(q->dequeue());
        count++;
    }
    while (!temp->isEmpty()) q->enqueue(temp->dequeue());
    delete temp;
    return count;
}

// --- Task 2 Implementations ---

void insert(Queue* q, int v, int pos) {
    int size = getSize(q);
    if (pos < 0 || pos > size || q->isFull()) return;

    Queue* temp = new MyQueue(MAX_SIZE);
    int currentPos = 0;

    while (!q->isEmpty()) {
        if (currentPos == pos) {
            temp->enqueue(v);
        }
        temp->enqueue(q->dequeue());
        currentPos++;
    }

    // If it needs to be inserted at the very end
    if (currentPos == pos) {
        temp->enqueue(v);
    }

    while (!temp->isEmpty()) {
        q->enqueue(temp->dequeue());
    }
    delete temp;
}

void insert(Queue* src, Queue* dst, int pos) {
    int dstSize = getSize(dst);
    if (pos < 0 || pos > dstSize) return;

    Queue* tempDst = new MyQueue(MAX_SIZE);
    Queue* tempSrc = new MyQueue(MAX_SIZE);
    int currentPos = 0;

    // Empty dst into tempDst, inserting src when we hit the position
    while (!dst->isEmpty()) {
        if (currentPos == pos) {
            while (!src->isEmpty() && !tempDst->isFull()) {
                int val = src->dequeue();
                tempDst->enqueue(val);
                tempSrc->enqueue(val); // Keep a copy to restore src
            }
        }
        if (!tempDst->isFull()) {
            tempDst->enqueue(dst->dequeue());
        }
        else {
            // Prevent loss of data if we hit max capacity
            dst->dequeue();
        }
        currentPos++;
    }

    // If inserting at the very end
    if (currentPos == pos) {
        while (!src->isEmpty() && !tempDst->isFull()) {
            int val = src->dequeue();
            tempDst->enqueue(val);
            tempSrc->enqueue(val);
        }
    }

    // Restore dst
    while (!tempDst->isEmpty()) {
        dst->enqueue(tempDst->dequeue());
    }
    // Restore src
    while (!tempSrc->isEmpty()) {
        src->enqueue(tempSrc->dequeue());
    }

    delete tempDst;
    delete tempSrc;
}

void shiftRight(Queue* q, int pos) {
    // Shifts elements from pos to the right. The last element wraps to pos.
    int size = getSize(q);
    if (pos < 0 || pos >= size - 1) return;

    Queue* temp = new MyQueue(MAX_SIZE);
    int lastElement;

    // First pass: find the very last element
    for (int i = 0; i < size; i++) {
        int val = q->dequeue();
        if (i == size - 1) lastElement = val;
        q->enqueue(val);
    }

    // Second pass: rebuild
    for (int i = 0; i < size - 1; i++) { // Process all except the last one
        int val = q->dequeue();
        if (i == pos) {
            temp->enqueue(lastElement);
        }
        temp->enqueue(val);
    }
    // Discard the last element from the queue as we already placed it
    q->dequeue();

    while (!temp->isEmpty()) {
        q->enqueue(temp->dequeue());
    }
    delete temp;
}

void shiftLeft(Queue* q, int pos) {
    // Takes the element at pos and moves it to the end of the queue.
    int size = getSize(q);
    if (pos < 0 || pos >= size) return;

    Queue* temp = new MyQueue(MAX_SIZE);
    int targetElement;

    for (int i = 0; i < size; i++) {
        int val = q->dequeue();
        if (i == pos) {
            targetElement = val;
        }
        else {
            temp->enqueue(val);
        }
    }

    // Put it at the end
    temp->enqueue(targetElement);

    while (!temp->isEmpty()) {
        q->enqueue(temp->dequeue());
    }
    delete temp;
}

int main() {
    Queue* A = new MyQueue(MAX_SIZE);
    A->enqueue(10);
    A->enqueue(9);
    A->enqueue(2);
    A->enqueue(5);
    A->enqueue(-7);

    cout << "Queue A Values: ";
    display(A, cout);

    Queue* B = new MyQueue(MAX_SIZE);
    insert(B, 100, 2); // B is currently empty, inserting at index 2 will fail safely or insert at 0
    cout << "Queue B Values after insert: ";
    display(B, cout);

    insert(A, B, 2);
    cout << "Queue B Values after insert from A: ";
    display(B, cout);

    shiftRight(B, 2);
    cout << "Queue B Values after shiftRight from pos 2: ";
    display(B, cout);

    shiftLeft(B, 2);
    cout << "Queue B Values after shiftLeft from pos 2: ";
    display(B, cout);

    return 0;
}