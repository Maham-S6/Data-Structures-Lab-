#include<iostream>
#include"onlinecourse.h"
#include"offlinecourse.h"
using namespace std; 
int main()
{
	onlinecourse o1(6, 7);
	offlinecourse o2(8, 9);
	cout << "Online course duration (in hours): " << o1.duration();
	
	cout << "\nOffline course duration (in hours): "<<o2.duration();

	return 0;
}