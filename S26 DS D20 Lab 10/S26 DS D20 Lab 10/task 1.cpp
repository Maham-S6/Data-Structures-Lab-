//Understanding the task:
/*The goal is to write the actual logic (main aka the body) for the functions of a Doubly Linked List. 
Unlike a simple linked list, each node here has two pointers: 
one pointing to the next person in line and one pointing back to the previous person. 
I need to make sure that when I add or remove a node, I update both pointers correctly so the chain doesn't break. */
//Implementation Strategy 
/*I will implement functions like insertAtFirst, insertAtLast, removeFromFirst, and removeFromLast.
Insertion: 
If I add a node "B" between "A" and "C", I must point A -> B, B -> A, B -> C, and C -> B.  
Deletion: 
To remove "B", I must link "A" directly to "C" (A -> C) and "C" directly back to "A" (C <- A) before deleting "B"*/

//I will use the Node structure (with next and prev pointers) and class variables like head and tail. These functions are the building blocks that will be reused in later tasks to build recursive versions of stacks and queues.

//Learning from the task 
/*I learnt how critical it is to manage the prev pointer. 
If you forget to update the back-link, the list becomes a one-way street, and you lose the benefit of a Doubly Linked List. */

//Skills developed 
/*I have developed skills in manual memory management and pointer manipulation. 
I can now code solutions for problems that require navigating data in both directions, like a "back" and "forward" button in a web browser.  */

#include <iostream>
#include"Node.h"
//I was to add header files here but I could not find the double linked list header file on portal, so I did not add that. 
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

template <typename T>
class ConcreteDoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    ConcreteDoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    bool isEmpty() {
        return head == nullptr;
    }

    //Implementation of Class Functions
    void insertAtFirst(T val) {
        Node<T>* newNode = new Node<T>{ val, head, nullptr };
        if (isEmpty()) {
            tail = newNode;
        }
        else {
            head->prev = newNode;
        }
        head = newNode;
        size++;
    }

    void insertAtLast(T val) {
        Node<T>* newNode = new Node<T>{ val, nullptr, tail };
        if (isEmpty()) {
            head = newNode;
        }
        else {
            tail->next = newNode;
        }
        tail = newNode;
        size++;
    }

    bool removeFromFirst(T& val) {
        if (isEmpty()) return false;
        Node<T>* temp = head;
        val = temp->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        else {
            head->prev = nullptr;
        }
        delete temp;
        size--;
        return true;
    }

    bool removeFromLast(T& val) {
        if (isEmpty()) return false;
        Node<T>* temp = tail;
        val = temp->data;
        tail = tail->prev;
        if (tail == nullptr) {
            head = nullptr;
        }
        else {
            tail->next = nullptr;
        }
        delete temp;
        size--;
        return true;
    }

    void display() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " <-> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    ConcreteDoublyLinkedList<int> list;

    cout << "Testing Doubly Linked List Implementation..." << endl;
    list.insertAtFirst(10);
    list.insertAtLast(20);
    list.insertAtFirst(5);

    cout << "Current List: ";
    list.display(); // Expected: 5 <-> 10 <-> 20 <-> NULL

    int val;
    list.removeFromLast(val);
    cout << "Removed from last: " << val << endl;

    cout << "Final List: ";
    list.display();

    return 0;
}