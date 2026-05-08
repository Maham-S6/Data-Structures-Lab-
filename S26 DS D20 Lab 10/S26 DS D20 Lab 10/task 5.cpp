//Understanding of the Task
/*The task requires converting iterative operations (copying, displaying, calculating size, and finding the maximum value) for a Doubly Linked List into recursive functions. 
A Doubly Linked List differs from a stack or queue as it has nodes with pointers to both the next and previous elements.*/

//Implementation Strategy 
/*Base Case: The recursion stops when the list is empty (isEmpty()). 
Recursive Step: For functions like display, we remove the first element, process it, recurse through the remaining list, and then re-insert the element at the front to restore the list's structure. 
Progression Notation: * List: (A <-> B <-> C)   
Remove A: List is (B <-> C)
Recurse: Process (B <-> C)
Return: Re-insert A to get (A <-> B <-> C).*/

//Functions Reused
/*isEmpty(): To check for the base case.  
removeFromFirst(v) or removeFromLast(v): To reduce the problem size.  
insertAtFirst(v) or insertAtLast(v): To rebuild and restore the list during the "rewinding" phase of recursion.*/

//Learning from the task 
/*I have learned that recursion on a Doubly Linked List effectively treats the system's call stack as temporary storage, allowing me to visit every node without an explicit pointer-based loop.*/

//Skills developed 
/*I am now capable of implementing complex list manipulations recursively, ensuring that pointer integrity is maintained even when the list is temporarily modified.*/

#include <iostream>
//Header files provided in the lab zip must be used 
using namespace std;

// 1. Recursive List Copy
void LLCopy(ConcreteDoublyLinkedList<int>& src, ConcreteDoublyLinkedList<int>& copy) {
    if (src.isEmpty()) return; // Base Case 

    int x;
    src.removeFromLast(x); // Step 1: Remove from end 
    LLCopy(src, copy);      // Step 2: Recurse 

    // Step 3: Re-insert to both to maintain original order 
    src.insertAtLast(x);
    copy.insertAtLast(x);
}

// 2. Recursive Display
void display(ConcreteDoublyLinkedList<int>& as) {
    if (as.isEmpty()) return; // Base Case 

    int v;
    as.removeFromFirst(v);    // Step 1: Remove 
    cout << v << " -> ";      // Step 2: Process 
    display(as);              // Step 3: Recurse

    as.insertAtFirst(v);      // Step 4: Restore 
}

// 3. Recursive Get Size
int getSize(ConcreteDoublyLinkedList<int>& as) {
    if (as.isEmpty()) return 0; // Base Case 

    int v;
    as.removeFromLast(v);       // Step 1: Remove 
    int count = 1 + getSize(as); // Step 2: Count 1 + rest 

    as.insertAtLast(v);         // Step 3: Restore
    return count;             
}

// 4. Recursive Max
int max(ConcreteDoublyLinkedList<int>& as) {
    int v;
    as.removeFromLast(v); // Step 1: Remove an element 

    if (as.isEmpty()) {
        as.insertAtLast(v);
        return v; // Smallest case: only one element 
    }

    int remainingMax = max(as); // Step 2: Get max of rest 
    int currentMax = (v > remainingMax) ? v : remainingMax;

    as.insertAtLast(v); // Step 3: Restore
    return currentMax;
}

// 5. Recursive Frequency
// Helper to count occurrences of target in the list recursively
int countOccurrences(ConcreteDoublyLinkedList<int>& as, int target) {
    if (as.isEmpty()) return 0;

    int v;
    as.removeFromFirst(v);
    int count = (v == target ? 1 : 0) + countOccurrences(as, target);

    as.insertAtFirst(v);
    return count;
}

ConcreteDoublyLinkedList<int> frequency(ConcreteDoublyLinkedList<int> adt) {
    ConcreteDoublyLinkedList<int> result;
    if (adt.isEmpty()) return result; // Base case 

    int v;
    adt.removeFromFirst(v);
    // Find frequency of current element using recursive helper 
    int freq = 1 + countOccurrences(adt, v);

    // Get frequencies of the remaining list
    result = frequency(adt);
    result.insertAtFirst(freq);

    adt.insertAtFirst(v); // Restore original list 
    return result;
}