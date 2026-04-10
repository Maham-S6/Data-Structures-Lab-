#include<iostream>
#include "MyStack.h"
#include "MyQueue.h"
#include "Stack.h"
#include "Queue.h"
#include <string>
using namespace std;


/* MANDATORY STEPS FOR TASK 3

1. Understanding the task:
I need to process a collection of numbers and remove any duplicates. The goal is to ensure that every number appears only once. If a number shows up a second or third time later in the line, it must be deleted. Crucially, the remaining numbers must stay in the same relative order they were originally in.

2. Solution description:
I will solve this by creating a new, empty temporary line to act as a "storage for unique items." I'll take items out of the original line one by one. Before adding an item to my unique storage, I will check if that number is already inside it.
To check, I have to unpack the unique storage line into another small helper line, comparing each value as I go. If the number isn't found after checking everything, I add it to the unique storage. If it is already there, I just throw it away. At the very end, I move all the items from my unique storage back into the original line so the results are saved.

3. Reusing functions:
I am reusing the basic adding and removing actions (enqueue and dequeue). I also use a helper function to find the size of the line so I know exactly how many times to run my comparison loops.

4. Learning from the task:
I learned that performing a "search" or "unique" operation on a line is quite heavy because you have to constantly move items back and forth between temporary containers to see what is inside without losing the data.

5. Skills developed:
I have improved my ability to manage multiple data containers at once. This logic is very similar to how a computer might filter out duplicate notifications or clean up a list of unique web visitors.
*/

// Helper to get size since it's used for looping
int getSize(Queue* q) {
    Queue* temp = new MyQueue(10);
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

// Global function to remove duplicates
void unique(Queue* q) {
    if (q->isEmpty()) return;

    int currentSize = getSize(q);
    Queue* uniqueQ = new MyQueue(currentSize);

    while (!q->isEmpty()) {
        int currentVal = q->dequeue();
        bool alreadyExists = false;

        // Use a temporary queue to check if currentVal is already in uniqueQ
        Queue* checkTemp = new MyQueue(currentSize);
        while (!uniqueQ->isEmpty()) {
            int val = uniqueQ->dequeue();
            if (val == currentVal) {
                alreadyExists = true;
            }
            checkTemp->enqueue(val);
        }

        // Restore uniqueQ from the checkTemp
        while (!checkTemp->isEmpty()) {
            uniqueQ->enqueue(checkTemp->dequeue());
        }
        delete checkTemp;

        // If it wasn't found, it's unique; add it to our collection
        if (!alreadyExists) {
            uniqueQ->enqueue(currentVal);
        }
    }

    // Move everything back from uniqueQ to the original queue
    while (!uniqueQ->isEmpty()) {
        q->enqueue(uniqueQ->dequeue());
    }
    delete uniqueQ;
}

int main() {
    Queue* q = new MyQueue(10);

    // Test data from lab manual: 1, 2, 2, 1, 3, 1
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(2);
    q->enqueue(1);
    q->enqueue(3);
    q->enqueue(1);

    cout << "Original Queue: ";
    q->display(cout);
    cout << endl;

    unique(q);

    cout << "Queue after unique() operation: ";
    q->display(cout);
    cout << endl;

    return 0;
}