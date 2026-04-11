#include<iostream>
using namespace std;

// The Node class is the building block for the list
class Node
{
public:
    int data;    // The actual value we want to store
    Node* next;  // A pointer to the next node in the sequence
};