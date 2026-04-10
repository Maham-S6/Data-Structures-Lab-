#include <iostream>
#include"LinkedList.h"
#include"Node.h"
using namespace std;

class myLinkedList : public LinkedList
{
public:
    void insertAtLast(int value);
    void insertAtFirst(int value);
    void display();
    int removeFromFirst();
    int removeFromLast();
    bool isEmpty();

    // Functions for Task Two
    int getSize();
    bool search(int v);
    int peek(int pos);
    int get(int pos);
};

// Simple check to see if we have any data yet
bool myLinkedList::isEmpty()
{
    return first == nullptr && last == nullptr;
}

// Adds a new node to the front of the list
void myLinkedList::insertAtFirst(int value)
{
    Node* nn = new Node;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty()) {
        first = last = nn;
    }
    else {
        nn->next = first;
        first = nn;
    }
}

// Adds a new node to the back of the list
void myLinkedList::insertAtLast(int value)
{
    Node* nn = new Node;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty()) {
        first = last = nn;
    }
    else {
        last->next = nn;
        last = nn;
    }
}

// Loops through the list and prints values in a readable format
void myLinkedList::display()
{
    Node* t = first;
    while (t != nullptr) {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL\n";
}

// Removes the first node and returns its data
int myLinkedList::removeFromFirst()
{
    if (isEmpty()) return -99999;

    Node* t = first;
    int val = t->data;

    first = first->next;
    if (first == nullptr) last = nullptr;

    delete t;
    return val;
}

// Removes the last node (requires a bit of traversing to find the tail)
int myLinkedList::removeFromLast()
{
    if (isEmpty()) return -99999;

    if (first == last) {
        int val = first->data;
        delete first;
        first = last = nullptr;
        return val;
    }

    Node* t = first;
    while (t->next != last)
    {
        t = t->next;
    }

    int val = last->data;
    delete last;
    last = t;
    last->next = nullptr;

    return val;
}

// 1. getSize() - returns the total count of elements
int myLinkedList::getSize()
{
    int count = 0;
    Node* t = first;

    while (t != nullptr)
    {
        count++;
        t = t->next;
    }
    return count;
}

// 2. search() - looks for a specific value in the list
bool myLinkedList::search(int v)
{
    Node* t = first;

    while (t != nullptr)
    {
        if (t->data == v)
            return true; // Found it!
        t = t->next;
    }
    return false; // Not in the list
}

// 3. peek() - looks at the data at a certain position without deleting it
int myLinkedList::peek(int pos)
{
    if (pos < 0) return -99999;

    Node* t = first;
    int index = 0;

    while (t != nullptr)
    {
        if (index == pos)
            return t->data;
        t = t->next;
        index++;
    }

    return -99999; // Position doesn't exist
}

// 4. get() - removes and returns the item at a specific position
int myLinkedList::get(int pos)
{
    if (pos < 0 || isEmpty())
        return -99999;

    // Use our existing function if they want the first item
    if (pos == 0)
    {
        return removeFromFirst();
    }

    Node* prev = first;
    Node* curr = first->next;
    int index = 1;

    while (curr != nullptr)
    {
        if (index == pos)
        {
            int val = curr->data;
            prev->next = curr->next;

            // Update tail pointer if we just removed the last node
            if (curr == last)
                last = prev;

            delete curr;
            return val;
        }

        prev = curr;
        curr = curr->next;
        index++;
    }

    return -99999;
}