#ifndef PATRON_H
#define PATRON_H

#include <iostream>
#include <string>
using namespace std;

class Patron {
	public:
		//Default consructor
		Patron();
		//Parameterized constructor
		Patron(string name, int id, float balance, int booksOut);
		//Sets
		void SetName(string name);
		void SetID(int id);
		void SetFineBalance(float balance);
		void SetCurrentBooksOut(int booksOuts);
		//Gets
		string GetName();
		int GetID();
		float GetBalance();
		int GetBooksOut();
	private:
		string Name;
		int idNum;
		float fineBalance;
		int numBooksOut;
};

#endif
