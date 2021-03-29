#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
using namespace std;

class LibraryItem {
public:
	LibraryItem();
	LibraryItem(int id, float cost, int status, int loanperiod);
	
	int GetID();
	float GetCost();
	int GetStatus();
	int GetLoanPeriod();

	void SetID(int id);
	void SetCost(float cost);
	void SetStatus(int status);
	void SetLoanPeriod(int loanperiod);

	virtual int Print(int type);
	virtual int RawPrint(int type);
	friend ostream& operator<<(ostream& st, LibraryItem& li);
	virtual ~LibraryItem() {};

protected:
	int ID;
	float Cost;
	int Status;
	int LoanPeriod;
};

#endif