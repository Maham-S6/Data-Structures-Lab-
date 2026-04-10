#include <iostream>
#include "AbstractArray.h"
#include"MyArray.h"
using namespace std; 

int main()
{
    MyArray A(MAX_SIZE);
    int n = 0;

    cout << "Please select a number between 1 and " << MAX_SIZE << ": ";
    cin >> n;

    read(A, cin, n);
    cout << "Array A Values: ";
    display(A, cout);

    MyArray B(MAX_SIZE);
    copy(A, B);
    cout << "Array B Values: ";
    display(B, cout);

    MyArray C(MAX_SIZE);
    C.add(9);
    C.add(7);
    C.add(5);

    insert(A, C, 2);
    cout << "Array C Values: ";
    display(C, cout);

    shiftLeft(C, 2);
    cout << "Array C Values: ";
    display(C, cout);

    shiftRight(C, 2);
    cout << "Array C Values: ";
    display(C, cout);

    int mx = 0;
    float ag = 0.0;

    stats(C, mx, ag);
    cout << "Array C Values: ";
    display(C, cout);
    cout << "Average is " << ag << " maximum is " << mx << endl;

    return 0;
}