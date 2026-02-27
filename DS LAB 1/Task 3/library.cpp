#pragma once
#include"newspaper.h"
#include"book.h" 
#include <iostream>
class Library 
{
private:
    book books[100];
    newspaper newspapers[100];
    int bookCount;
    int newspaperCount;

public:
    void addbook(book b) {
        books[bookCount] = b;
        bookCount++;
    }

    void addnewspaper(newspaper n) {
        newspapers[newspaperCount] = n;
        newspaperCount++;
    }

    void displayCollection() {

        cout << "\nBooks:\n";
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }

        cout << "\nNewspapers:\n";
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = i + 1; j < bookCount; j++) {
                if (books[i].getPages() > books[j].getPages()) {
                    book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = i + 1; j < newspaperCount; j++) {
                if (newspapers[i].getEdition() > newspapers[j].getEdition()) {
                    Newspaper temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
            }
        }
    }

    book* searchBookByTitle(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                return &books[i];
            }
        }
        return NULL;
    }

    newspaper* searchNewspaperByName(string name) {
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i].getTitle() == name) {
                return &newspapers[i];
            }
        }
        return NULL;
    }
};