#include <vector>
#include <iostream>
using namespace std;

class Loans 
{
public:
	Loans();

	int GetCount();
	void iCount();
	void dCount();

	void AddLoan();//check out
	void DeleteLoan(int); //check in
	int FindLoan(int);
	void PrintLoansAll();
	void PrintOverdue();
	void EditLoan(); //re-check
	void UpdateStatus();
	void ReportLost();

	void LoadLoans();
	void StoreLoans();
	void CleanUp();


private:
	int loanCount;
	vector<Loan*> loanList;
};