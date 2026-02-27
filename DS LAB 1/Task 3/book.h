#pragma once
#include"libraryitem.h"
#include<iostream>
using namespace std;
class book:public libraryitem
{
protected:
	string author;
	int page;
public:
	void setname(string name)
	{
		author = name;
	}
	string getname()
	{
		return author;
	}
	void page(int p)
	{
		page = p;
	}
	int getpage()
	{
		return page;
	}
	book(string title, string name, int p) :libraryitem(title)
	{
		author = name;
		page = p;
	}
	void display()
	{
		cout << "\nBook title: " << title;
		cout << "\nAuthor name: " << author;
		cout << "Book page: " << page;
	}
};

