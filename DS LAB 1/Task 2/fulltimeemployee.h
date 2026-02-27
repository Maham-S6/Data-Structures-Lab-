#pragma once
#include"employee.h"
#include<iostream>
using namespace std;
class fulltimeemployee
{
private:
	float fixedsalary;
public: 
	fulltimeemployee(float fs)
	{
		fixedsalary = fs;
	}
	float calculatesalary()
	{
		return fixedsalary;
	}
};

