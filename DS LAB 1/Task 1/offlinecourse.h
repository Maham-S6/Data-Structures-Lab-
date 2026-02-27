#pragma once
#include "course.h"
#include<iostream>
class offlinecourse
{
private: 
	int months;
	int hoursperday;
public:
	offlinecourse(int m, int h)
	{
		months = m;
		hoursperday = h;
	}
	int duration()
	{
		return months * hoursperday;
	}
};

