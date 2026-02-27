#pragma once
#include"employee.h"
#include<iostream>
using namespace std; 
class parttimeemployee
{
private: 
	int hours;
	double rate; 
public: 
	parttimeemployee(int h, float r)
	{
		hours = h;
		rate = r;
	}
	double calculatesalary()
	{
		return hours * rate;
	}
};

