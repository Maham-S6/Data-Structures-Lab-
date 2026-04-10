#include<iostream>
#include"node.h"
using namespace std;

class LinkedList // This is an abstract class
{
protected:
    Node* first; // Points to the start of the list
    Node* last;  // Points to the very end

public:
    // Constructor sets everything to null so we start with an empty list
    LinkedList()
    {
        first = nullptr;
        last = nullptr;
    };

    // Destructor to tidy up memory; we loop through and delete every node
    ~LinkedList()
    {
        Node* temp = first;
        while (temp != nullptr)
        {
            Node* nextnode = temp->next;
            delete temp;
            temp = nextnode;
        }
        first = nullptr;
        last = nullptr;
    }

    // These are the blueprints for what the list should be able to do
    virtual void insertAtLast(int) = 0;
    virtual void insertAtFirst(int) = 0;
    virtual int removeFromFirst() = 0;
    virtual int removeFromLast() = 0;
    virtual bool isEmpty() = 0;
    virtual void display() = 0;
};