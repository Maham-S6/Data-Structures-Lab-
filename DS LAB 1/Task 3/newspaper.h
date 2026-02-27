#pragma once
#include "libraryitem.h"
#include <iostream>
using namespace std;
class newspaper:public libraryitem
{
protected:
	string publishing;
	string edition;
public: 
	void setpublishing(string date)
	{
		publishing = date;
	}
	string getpublishing()
	{
		return publishing;
	}
	void setedition(string e)
	{
		edition = e;
	}
	string getedition()
	{
		return edition;
	}
	newspaper(string title, string date, string e) :libraryitem(title)
	{
		publishing = date;
		edition = e;
	}
	void display()
	{
		cout << "\n Newspaper title: " << title;
		cout << "\nPublishing Date(yy-mm-dd): " << publishing;
		cout << "\nEdition: " << edition;
	}
};

