//Understanding the task 
/*The objective is to convert six common iterative algorithms—counting down, summing numbers, finding a maximum value, counting digits, displaying digits, and binary search—into their recursive equivalents. 
Instead of using for or while loops, these functions must now call themselves with a reduced version of the original problem until they reach a stopping point.*/

//Implementation Strategy 
/*Counting Down : Instead of a loop, the function prints the current number and calls itself with n - 1.
Summation : The base case is when n reaches 0. Otherwise, the function returns n plus the result of the function called with n - 1.
Max in Array : We compare the last element of the current range with the maximum found in the rest of the array.
Count / Display Digits : We use modulo(%) to isolate the last digit and division to reduce the number for the next recursive call.
Binary Search : We check the middle element, if not found, we recursively call the function on either the left or right half by updating the low or high boundaries.*/

//Learning from the task 
/*I have learned how to identify the "base case" to prevent infinite recursion and how to break a large problem into identical smaller sub-problems.
I can now implement recursive logic for data traversal and searching, which is a foundational skill for handling complex data structures. */

#include <iostream>
using namespace std;

// 1. Recursive Countdown
// Base Case: n <= 0
// Nth Case: Print n, then call func(n-1)
void func(int n) {
    if (n <= 0) return; // Smallest case
    cout << n << endl;
    func(n - 1); // Recursive call
}

// 2. Recursive Sum
// Base Case: n == 0 returns 0
// Nth Case: return n + sum(n-1)
int sum(int n) {
    if (n <= 0) return 0;
    return n + sum(n - 1);
}

// 3. Recursive Max in Array
// Base Case: size == 1 returns a[0]
// Nth Case: compare a[size-1] with max of remaining array
int maxRecursive(int a[], int size) {
    if (size == 1) return a[0];
    int currentMax = maxRecursive(a, size - 1);
    return (a[size - 1] > currentMax) ? a[size - 1] : currentMax;
}

// 4. Recursive Count Digits
// Base Case: n == 0 returns 0
// Nth Case: return 1 + countDigits(n/10)
int countDigits(int n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}

// 5. Recursive Display Digits
// Base Case: n == 0
// Nth Case: display n%10, then call displayDigits(n/10)
void displayDigits(int n) {
    if (n == 0) return;
    cout << n % 10 << " ";
    displayDigits(n / 10);
}

// 6. Recursive Binary Search
// Base Case: low > high (not found) or a[mid] == v
// Nth Case: Search left half or right half
int binarySearch(int a[], int low, int high, int v) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (a[mid] == v) return mid;
    if (v > a[mid]) return binarySearch(a, mid + 1, high, v);
    return binarySearch(a, low, mid - 1, v);
}

int main() {
    // Testing Countdown
    cout << "Countdown from 5:" << endl;
    func(5);

    // Testing Sum
    cout << "Sum up to 10: " << sum(10) << endl;

    // Testing Max
    int arr[] = { 1, 5, 3, 9, 2 };
    cout << "Max in array: " << maxRecursive(arr, 5) << endl;

    // Testing Digits
    cout << "Digits in 1234: " << countDigits(1234) << endl;
    cout << "Displaying 1234 reversed: ";
    displayDigits(1234);
    cout << endl;

    // Testing Binary Search
    int sortedArr[] = { 10, 20, 30, 40, 50 };
    cout << "Index of 40: " << binarySearch(sortedArr, 0, 4, 40) << endl; 

    return 0; 
}