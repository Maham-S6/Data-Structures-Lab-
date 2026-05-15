#include <iostream>
#include "MyStack.h" 

using namespace std;

/* 1. my uderstanding of code 
This task is about using a Stack but doing everything through recursion instead of
using loops. 
I need to solve three main problems: 
solving math expressions that start with operators (prefix)
solving math expressions where operators come at the end (postfix) 
moving a whole stack of numbers to another stack while following the no bigger number on top of a smaller one rule.
The goal is to handle the stack data structure without ever writing while or for.

2. how i will implement this code 
- For Prefix: I will read the string from right to left. If it's a number, I'll
  put it in the stack. If it's an operator, I'll pull two numbers out, do the
  math, and put the result back.
- For Postfix: This is similar but I read from left to right.
- For no bigger number on top of a smaller one rule Copy: I will use a third "extra" stack. To move numbers,
  I'll recursively move all the smaller ones out of the way to the extra stack,
  place the target number, and then move them back.

3. functions i will use and why 
I will use the push, pop, and isEmpty functions from the MyStack class. 
These are necessary to actually move the data in and out of the arrays. 
I'm also reusing a helper for the math logic so I don't have to write the same plus/minus code in two different places.

4. my learning from the task 
I learned that the no bigger number on top of a smaller one rule logic is a perfect example of how recursion
works. this rule is called the Tower of Hanoi. 

5. skills i developed 
I've developed a better understanding of how to process mathematical strings
manually. I also now know how to manage multiple data structures (like three
different stacks) at once using recursive calls.
*/

// Helper to do the actual math
int calculate(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

// 1. Evaluating Prefix (reading from right to left)
int evaluatePrefix(char* expression, MyStack s) {
    static int i = -1;
    if (i == -1) { // to find end of string first
        int len = 0;
        while (expression[len] != '\0') len++;
        i = len - 1;
    }

    if (i < 0) {
        int result;
        s.pop(result);
        i = -1; // reset for next run
        return result;
    }

    char c = expression[i--];

    if (c >= '0' && c <= '9') {
        s.push(c - '0');
    }
    else {
        int val1, val2;
        s.pop(val1);
        s.pop(val2);
        s.push(calculate(val1, val2, c));
    }
    return evaluatePrefix(expression, s);
}

// 2. Evaluate Postfix (reading from left to right)
int evaluatePostfix(char* expression, MyStack s) {
    if (*expression == '\0') {
        int result;
        s.pop(result);
        return result;
    }

    if (*expression >= '0' && *expression <= '9') {
        s.push(*expression - '0');
    }
    else {
        int val2, val1; // Order matters for division/subtraction
        s.pop(val2);
        s.pop(val1);
        s.push(calculate(val1, val2, *expression));
    }
    return evaluatePostfix(expression + 1, s);
}

// 3. Copy TOH logic
// Using a third temporary stack to satisfy the no larger on smaller rule
void moveDisks(int n, MyStack& src, MyStack& dest, MyStack& helper) {
    if (n <= 0) return;

    // Move n-1 from src to helper
    moveDisks(n - 1, src, helper, dest);

    // Move the nth disk from src to dest
    int val;
    src.pop(val);
    dest.push(val);

    // Move n-1 from helper to dest
    moveDisks(n - 1, helper, dest, src);
}

void copyTOH(MyStack src, MyStack& copy) {
    MyStack temp(10); // temporary helper stack
    // We assume the size is the 'count' in the stack
    // Since we need to know how many to move:
    int n = 0;
    MyStack countCopy = src;
    int dummy;
    while (countCopy.pop(dummy)) n++;

    moveDisks(n, src, copy, temp);
}

int main() {
    MyStack s(10);

    char post[] = "23+4*"; 
    cout << "Postfix 23+4* Result: " << evaluatePostfix(post, s) << endl;

    char pre[] = "*+234"; 
    cout << "Prefix *+234 Result: " << evaluatePrefix(pre, s) << endl;

    // TOH Copy test
    MyStack source(10);
    source.push(3);
    source.push(2);
    source.push(1); // 1 is on top

    MyStack destination(10);
    copyTOH(source, destination);

    cout << "TOH Copy Top: " << destination.top() << endl;

    return 0;
}