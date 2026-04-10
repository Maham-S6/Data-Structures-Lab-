#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"

/* MANDATORY STEPS FOR TASK 4

1. Understanding the task:
I need to take a specific number 'k' and reverse only that many items at the start of my line. The rest of the items that come after 'k' should stay in their original order. I have to be careful not to lose any data and ensure the final arrangement is correct.

2. Solution description:
I will use a pile (Stack) to help me reverse the items. First, I will count how many items are in the line in total. Then, I will take the first 'k' items from the front and put them onto the pile.
Because a pile gives back the last thing you put in first, when I take them off the pile and put them back into the line, they will be reversed. However, they will now be at the back of the line.
To fix this, I will take the remaining items (the ones I didn't want to reverse) from the front and immediately move them to the back. This cycles the reversed items back to the front where they belong.

3. Reusing functions:
I am reusing the 'getSize' logic to determine the total count of elements. I am also using the basic 'push' and 'pop' actions for the pile, and 'enqueue' and 'dequeue' for the line.

4. Learning from the task:
I learned how a pile and a line can work together to change the order of data. A line keeps things in order, while a pile flips them.

5. Skills developed:
I have improved my ability to perform partial data manipulation. This is useful for systems where you might want to re-prioritise only a small batch of tasks without messing up the entire schedule.
*/

// Helper to find size
int getSize(Queue* q) {
    Queue* temp = new MyQueue(20);
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

void reverseFirstK(Queue* q, int k) {
    int total = getSize(q);
    if (q->isEmpty() || k > total || k <= 0) return;

    // Justification: We use a Stack because it naturally reverses order (LIFO),
    // which is required to reverse the first k elements efficiently.
    Stack* pile = new MyStack(k);

    // 1. Dequeue first k elements and push them onto the stack
    for (int i = 0; i < k; i++) {
        pile->push(q->dequeue());
    }

    // 2. Pop from stack and enqueue back to the queue
    // These k elements are now at the BACK of the queue in reverse order
    while (!pile->isEmpty()) {
        int val;
        pile->pop(val);
        q->enqueue(val);
    }

    // 3. Move the (total - k) elements from front to back to restore relative order
    for (int i = 0; i < (total - k); i++) {
        q->enqueue(q->dequeue());
    }

    delete pile;
}

int main() {
    Queue* q = new MyQueue(10);

    // Test data: [10, 20, 30, 40, 50], k = 3
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);

    cout << "Original Queue: ";
    q->display(cout);
    cout << endl;

    int k = 3;
    reverseFirstK(q, k);

    cout << "After reversing first " << k << " elements: ";
    q->display(cout);
    cout << endl;

    return 0;
}