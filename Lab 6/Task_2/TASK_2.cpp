#include<iostream>
#include"myLinkedList.h"
using namespace std;

int main()
{
    myLinkedList list;

    // Fill the list with some test values
    list.insertAtLast(10);
    list.insertAtLast(20);
    list.insertAtLast(30);
    list.insertAtLast(40);

    cout << "Linked List: ";
    list.display();

    // Check if getSize works
    cout << "\nSize: " << list.getSize();

    // Check if search works for existing and non-existing numbers
    cout << "\nSearch 20: " << (list.search(20) ? "Found" : "Not Found");
    cout << "\nSearch 99: " << (list.search(99) ? "Found" : "Not Found");

    // Check peek logic
    cout << "\nPeek at position 2: " << list.peek(2);

    // Check get (removal) logic
    cout << "\nRemoved at position 1: " << list.get(1);

    cout << "\nUpdated List: ";
    list.display();

    return 0;
}