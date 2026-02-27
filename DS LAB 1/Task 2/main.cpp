#include<iostream>
#include"fulltimeemployee.h"
#include"parttimeemployee.h"
using namespace std; 
int main()
{
	fulltimeemployee fe(100000);
	parttimeemployee pe(9, 10000);
	cout << "\nFull time employee total salary: " << fe.calculatesalary();
	cout << "\nPart time employee salary: " << pe.calculatesalary() << endl;

	return 0;
}