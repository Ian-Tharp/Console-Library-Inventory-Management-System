#include <iostream>
#include "Loan.h"
using namespace std;

Loan::Loan()
{
	loanID = -1;
	itemLoc = -1;
	patronLoc = -1;
	Status = -1;
	timestamp = 0;
}

Loan::Loan(int id1, int id2, int id3, int status, time_t timenow)
{
	loanID = id1;
	itemLoc = id2;
	patronLoc = id3;
	Status = status;
	timestamp = timenow;
}
//Gets
int Loan::GetLoanID()
{
	return loanID;
}
int Loan::GetItemID()
{
	return itemLoc;
}
int Loan::GetPatronID()
{
	return patronLoc;
}
int Loan::GetStatus() {
	return Status;
}
time_t Loan::GetLoanTime()
{
	return timestamp;
}

//Sets
void Loan::SetLoanID(int id)
{
	loanID = id;
}
void Loan::SetItemID(int id)
{
	itemLoc = id;
}
void Loan::SetPatronID(int id)
{
	patronLoc = id;
}
void Loan::SetStatus(int status) {
	Status = status;
}
void Loan::SetLoanTime(time_t timenow)
{
	time_t curTime = time(0);
	timestamp = curTime;
	timestamp = timenow;
}
//Print
void Loan::PrintLoan()
{
	cout << "Loan ID: " << loanID << endl;
	cout << "Patron: " << patronLoc << endl;
	cout << "Item: " << itemLoc << endl;
}