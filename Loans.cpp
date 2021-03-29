#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>
#include <iterator>
#include "Patron.h"
#include "Patrons.h"
#include "Book.h"
#include "LibraryItem.h"
#include "LibraryItems.h"
#include "Loan.h"
#include "Loans.h"

extern Patrons patrons;
extern LibraryItems items;
extern Loans loans;

using namespace std;

Loans::Loans()
{
	loanCount = 0;
}

int Loans::GetCount()
{
	return loanCount;
}

void Loans::iCount()
{
	loanCount++;
}

void Loans::dCount()
{
	loanCount--;
}
//------------------------------
void Loans::AddLoan() //Check out
{
	int id1, id2, id3, status;
	Loan *temp;

	bool running = true;

	time_t timeNow, timedue;
	time_t timenow = time(0);
	char* t = ctime(&timenow);

	cout << "Enter new Loan ID: ";
	cin >> id1;
	cin.ignore();

	cout << "Enter Patron ID: ";
	while (running)
	{
		cin >> id2;
		if (id2 < 100000)
		{
			cout << "Not a 6 digit number, please try again." << endl;
		}
		else if (id2 > 999999)
		{
			cout << "Not a 6 digit number, please try again." << endl;
		}
		else
		{
			running = false;
			break;
		}
	}
	cin.ignore();

	cout << "Enter Item ID: ";
	cin >> id3;
	cin.ignore();
	status = 1;

	temp->SetLoanTime(timenow);

	cout << "Timestamp of Loan: " << t << endl;

	temp = new Loan(id1, id2, id3, status, timenow);
	loanList.push_back(temp);
	iCount();
}

void Loans::DeleteLoan(int id) //check in
{
	Loan* temp;
	
	for (auto it = loanList.begin(); it != loanList.end(); ++it)
	{
		if ((*it)->GetLoanID() == id)
		{
			it = loanList.erase(it);
			break;
		}
	}
	dCount();
}

void Loans::PrintLoansAll()
{
	Loan *temp;
	for (auto it = loanList.begin(); it != loanList.end(); ++it)
	{
		temp = *it;
		cout << "Loan ID: " << temp->GetLoanID();
		cout << "\nPatron ID: " << temp->GetPatronID();
		cout << "\nItem ID: " << temp->GetItemID();
		cout << "\nStatus: ";
		if (temp->GetStatus() == 1)
		{
			cout << "Checked out" << endl;
		}
		else if (temp->GetStatus() == 2)
		{
			cout << "Lost" << endl;
		}
		else if (temp->GetStatus() == 3)
		{
			cout << "In-stock" << endl;
		}
	}
}

int Loans::FindLoan(int id)
{
	Loan *temp;
	for (auto it = loanList.begin(); it != loanList.end(); ++it)
	{
		temp = *it;
		if ((*it)->GetLoanID() == id)
		{
			cout << "Loan ID: " << temp->GetLoanID();
			cout << "\nPatron ID: " << temp->GetPatronID();
			cout << "\nItem ID: " << temp->GetItemID();
			cout << endl;
		}
	}
}

void Loans::EditLoan() //Re-check
{
	int id;
	time_t timenow;

	cout << "Enter ID of Loan to Re-Check: ";
	cin >> id;
	for (int i = 0; i < loanCount; ++i)
	{
		if (loanList[i]->GetLoanID() == id)
		{
			//Add 10 days to timestamp
			break;
		}
	}
}

void Loans::PrintOverdue()
{
	cout << "Function not implemented." << endl;
}

void Loans::UpdateStatus()
{
	cout << "Function not implemented." << endl;
}

void Loans::ReportLost()
{
	int id, id1;
	string title;
	Patron* ptemp;
	LibraryItem* temp;
	Loan* ltemp;
	float balance;

	cout << "Enter ID of loan to report as lost: ";
	cin >> id;
	cout << "Enter ID of item to report as lost: ";
	cin >> id1;
	if (temp->GetID() == id1)
	{
		for (int i = 0; i < loanCount; ++i)
		{
			if (ltemp->GetLoanID() == id)
			{
				balance = temp->GetCost();
				balance = ptemp->GetBalance() + balance;
				ptemp->SetFineBalance(balance);
				temp->SetStatus(2);
				cout << "Item reported as lost. Updated Patron Balance and removed Loan." << endl;
				for (auto it = loanList.begin(); it != loanList.end(); ++it)
				{
					if ((*it)->GetLoanID() == id)
					{
						it = loanList.erase(it);
						dCount();
						break;
					}
				}
			}
		}
	}
	else {
		cout << "Unsuccessful to report as lost." << endl;
	}
}

//---------------------------------------------------------------------
void Loans::StoreLoans()
{
	ofstream fout;
	fout.open("loans.dat");
	fout << loanCount << endl;

	Loan *temp;
	for (auto it = loanList.begin(); it != loanList.end(); ++it)
	{
		temp = *it;
		fout << temp->GetLoanID() << " " << temp->GetPatronID() << " " << temp->GetItemID() << " " << temp->GetStatus() << " " << temp->GetLoanTime() << endl;
	}
	fout.close();
}
void Loans::LoadLoans()
{
	ifstream fin;
	int id1, id2, id3, status;
	time_t timenow;
	fin.open("loans.dat");
	fin >> loanCount; fin.ignore();

	for (int i = 0; i < loanCount; ++i)
	{
		fin >> id1;
		fin >> id2;
		fin >> id3;
		fin >> status;
		fin >> timenow;
		fin.ignore();
		loanList.push_back(new Loan(id1, id2, id3, status, timenow));
	}
	fin.close();
}
void Loans::CleanUp()
{
	for (auto it = loanList.begin(); it != loanList.end(); ++it)
	{
		delete* it;
	}
	loanList.clear();
}