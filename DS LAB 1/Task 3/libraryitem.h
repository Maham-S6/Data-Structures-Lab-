//GitHub link: https://github.com/Maham-S6/Data-Structures-Lab-.git

#pragma once
#include<iostream>
using namespace std;
class libraryitem {
protected:
    string title;

public:
    libraryitem(string t)
    {
        title = t;
    }
    string gettitle() 
    {
        return title;
    }
    // Pure virtual function
    virtual void display() = 0; 
};

