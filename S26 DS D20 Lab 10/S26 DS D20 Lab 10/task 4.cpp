//Understanding of the Task
//The objective is to replace iterative while loops with recursive calls for Queue operations including copying, displaying, and finding the maximum value.
// In a Queue, dequeue removes the front element, and enqueue adds to the back. 
 
//Implementation Strategy 
// Base Case:
// The recursion stops when isEmpty() returns true.
// Recursive Step : 
// We dequeue the front element, store it in the function's local memory, call the function again for the remaining elements, and then enqueue the element back to restore the Queue's original state.
//Progression Notation: 
//Front -> Back: (A -> B-> C ->).  
//Dequeue A:(B -> C ->).  
//Recursive Call.
//Enqueue A:(B -> C -> A ->)
// Note: To maintain the exact original order, a full rotation equal to the Queue size is often required.

//Learning from the task 
/*I have learned how to use recursion to traverse FIFO structures.
Unlike a Stack, restoring a Queue to its original order requires careful management of the front and back pointers during recursive returns.*/

//Skills developed 
/*I can now solve problems involving linear data ordering and frequency analysis using purely recursive logic.*/

#include <iostream>
using namespace std;

// 1. Recursive Copy Queue
// Base Case: src is empty
// Nth Case: Dequeue, recurse, then enqueue to both to maintain order
void copyQueue(ArrayQueue<int>& src, ArrayQueue<int>& copy) {
    if (src.isEmpty()) return;  

    int v = src.dequeue(); 
    copyQueue(src, copy);

    // Restore original and build copy
    src.enqueue(v); 
    copy.enqueue(v);
}

// 2. Recursive Display
void display(ArrayQueue<int>& as) {
    if (as.isEmpty()) return; 

    int v = as.dequeue(); 
    cout << v << " "; 
    display(as);

    as.enqueue(v); // Restore original state
}

// 3. Recursive Get Size
int getSize(ArrayQueue<int>& as) {
    if (as.isEmpty()) return 0; 

    int v = as.dequeue();
    int count = 1 + getSize(as); 

    as.enqueue(v); // Restore
    return count; 
}

// 4. Recursive Max
int max(ArrayQueue<int>& as) {
    int v = as.dequeue();

    if (as.isEmpty()) {
        as.enqueue(v);
        return v;
    }

    int remainingMax = max(as);
    int currentMax = (v > remainingMax) ? v : remainingMax; 

    as.enqueue(v); // Restore
    return currentMax; 
}

// 5. Frequency Function (Recursive)
// Helper to count occurrences of a specific value v in the queue
int countOccurrences(ArrayQueue<int>& as, int target) {
    if (as.isEmpty()) return 0;

    int v = as.dequeue();
    int count = (v == target ? 1 : 0) + countOccurrences(as, target);

    as.enqueue(v);
    return count;
}

ArrayQueue<int> frequency(ArrayQueue<int> adt) {
    ArrayQueue<int> result;
    if (adt.isEmpty()) return result; 

    int v = adt.dequeue();
    // Use recursive helper to find frequency of current element
    int freq = 1 + countOccurrences(adt, v);

    // Get frequency of the rest of the queue
    result = frequency(adt);
    result.enqueue(freq);

    adt.enqueue(v); // Restore original
    return result;
}