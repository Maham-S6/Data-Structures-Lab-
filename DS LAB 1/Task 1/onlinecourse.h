#pragma once
#include"course.h"
#include<iostream>
using namespace std;
class onlinecourse
{
private: 
	int weeks;
	int hoursperweek;
public:
	onlinecourse(int w, int hours)
	{
		weeks = w;
		hoursperweek = hours;
	}
	int duration()
	{
		return weeks * hoursperweek;
	}
};

