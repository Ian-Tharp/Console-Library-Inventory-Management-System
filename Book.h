#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include <iostream>
#include <string>
using namespace std;

class Book : public LibraryItem {
	public:
		//Default Constructor
		Book();
		Book(int id, float cost, int status, int loanperiod, string author, string title, string isbn, string category);
		//Sets
		void SetAuthor(string author);
		void SetTitle(string title);
		void SetISBN(string isbn);
		void SetCategory(string category);

		void Print();
		int RawPrint(int type);

		//Gets
		string GetAuthor();
		string GetTitle();
		string GetISBN();
		string GetCategory();

	private:
		string Author;
		string Title;
		string ISBN;
		string Category;
};

#endif