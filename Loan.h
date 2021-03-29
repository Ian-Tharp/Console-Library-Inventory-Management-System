#ifndef LOAN_H
#define LOAN

#include <ctime>
#include <time.h>

class Loan
{
public:
	Loan();
	Loan(int id1, int id2, int id3, int status, time_t timenow);

	int GetLoanID();
	int GetItemID();
	int GetPatronID();
	int GetStatus();
	time_t GetLoanTime();

	void SetLoanID(int);
	void SetItemID(int);
	void SetPatronID(int);
	void SetStatus(int);
	void SetLoanTime(time_t timenow);

	void PrintLoan();

private:
	int loanID;
	int itemLoc;
	int patronLoc;
	int Status;
	time_t timestamp;
};

#endif