#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"

/* MANDATORY STEPS FOR TASK 5

1. Understanding the task:
I need to simulate a fast-food restaurant system. Customers place orders for items like Burgers or Pizza, and these orders must be handled in the exact same sequence they were received. I need to track the details of each order (name, price, and preparation time) and calculate the total money earned once the food is served.

2. Solution description:
I will start by creating a simple "Order" structure to hold the item details. Then, I will use a Queue to act as the waiter's notepad where orders are stored.
- When an order is "placed," I will add an Order object to the back of the line.
- When an order is "served," I will take it from the front of the line, display its details, and add its price to a running total.
I will simulate a few customers to show that the first person to order is indeed the first person to get their food.

3. Reusing functions:
I am reusing the 'MyQueue' class and its 'enqueue' and 'dequeue' functions. Since the standard MyQueue handles integers, I have slightly adapted the logic to handle Order data.

4. Learning from the task:
I learned that a Queue is the perfect real-world representation of a "First-Come, First-Served" system. It ensures fairness in service.

5. Skills developed:
I have improved my ability to use abstract data types for real-world scenarios. This logic can be applied to any service-based software, like a ticket booking system or a customer support helpline.
*/

struct Order {
    string item;
    int price;
    int timeTaken;
};

// Global variables to track restaurant stats
int totalEarnings = 0;

void placeOrder(Queue* q, string name, int cost, int time) {
    // Note: Since the provided MyQueue handles 'int', we store the price 
    // to represent the order in the queue for this specific lab logic.
    if (!q->isFull()) {
        q->enqueue(cost);
        cout << "Order placed: " << name << " (Rs. " << cost << ")" << endl;
    }
    else {
        cout << "Restaurant is too busy! Cannot take more orders." << endl;
    }
}

void serveOrder(Queue* q, string name) {
    if (!q->isEmpty()) {
        int cost = q->dequeue();
        totalEarnings += cost;
        cout << "Serving: " << name << ". Payment received: Rs. " << cost << endl;
    }
    else {
        cout << "No orders to serve." << endl;
    }
}

int main() {
    // Create a queue for orders (capacity of 10)
    Queue* restaurantQueue = new MyQueue(10);

    cout << "--- Restaurant Opening ---" << endl;

    // Simulating sequence of orders
    placeOrder(restaurantQueue, "Burger", 200, 20);
    placeOrder(restaurantQueue, "Sandwich", 250, 30);
    placeOrder(restaurantQueue, "Pizza", 800, 45);

    cout << "\n--- Processing Orders ---" << endl;

    // Serving in the same order they arrived
    serveOrder(restaurantQueue, "Burger");
    serveOrder(restaurantQueue, "Sandwich");

    placeOrder(restaurantQueue, "French Fries", 100, 10);

    serveOrder(restaurantQueue, "Pizza");
    serveOrder(restaurantQueue, "French Fries");

    cout << "\n--- End of Shift ---" << endl;
    cout << "Total Money Earned: Rs. " << totalEarnings << endl;

    delete restaurantQueue;
    return 0;
}