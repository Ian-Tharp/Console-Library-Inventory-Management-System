/*
	Ian Tharp - IanTharp2@my.unt.edu
	Professor Keathley
	10/30/20
	Homework Assignment #4 - Library Inventory Management
	Referenced 100section.zip from the provided examples from lecture modules
*/
#include "Patron.h"
#include "Patrons.h"
#include "LibraryItem.h"
#include "LibraryItems.h"
#include "Cd.h"
#include "DvD.h"
#include "Book.h"
#include "Loan.h"
#include "Loans.h"
using namespace std;

Patrons patrons;
LibraryItems items;
Loans loans;

void PrintMain()
{
	cout << "\tMAIN MENU" << endl;
	cout << "\t1 - Patrons" << endl;
	cout << "\t2 - Books" << endl;
	cout << "\t3 - DVD's" << endl;
	cout << "\t4 - Audio CD's" << endl;
	cout << "\t5 - Loans" << endl;
	cout << "\t0 - Quit" << endl;
	cout << endl;
	cout << "Choose an option: ";
}

void PrintPatron()
{
	cout << endl;
	cout << "\tPATRON MENU" << endl;
	cout << "\t1 - Add Patron" << endl;
	cout << "\t2 - Edit Patron" << endl;
	cout << "\t3 - Delete Patron" << endl;
	cout << "\t4 - Find Patron by ID" << endl;
	cout << "\t5 - Print Patron" << endl;
	cout << "\t6 - Print All Patrons" << endl;
	cout << "\t7 - Pay Fines" << endl;
	cout << "\t0 - Return to Main Menu" << endl;
	cout << endl;
	cout << "Choose an option: ";
}

void PrintBook()
{
	cout << endl;
	cout << "\tBOOK MENU" << endl;
    cout << "\t1 - Add Book" << endl;
    cout << "\t2 - Edit Book" << endl;
    cout << "\t3 - Delete Book" << endl;
    cout << "\t4 - Find Book" << endl;
    cout << "\t5 - Print Book" << endl;
    cout << "\t6 - Print All Books" << endl;
	cout << "\t0 - Return to Main Menu" << endl;
    cout << endl;
    cout << "Choose an option: ";
}

void PrintCD()
{
	cout << endl;
	cout << "\tAUDIO CD MENU" << endl;
	cout << "\t1 - Add CD" << endl;
	cout << "\t2 - Edit CD" << endl;
	cout << "\t3 - Delete CD" << endl;
	cout << "\t4 - Find CD" << endl;
	cout << "\t5 - Print CD" << endl;
	cout << "\t6 - Print All CDs" << endl;
	cout << "\t0 - Return to Main Menu" << endl;
	cout << endl;
	cout << "Choose an option: ";
}

void PrintDVD()
{
	cout << endl;
	cout << "\tDVD MENU" << endl;
	cout << "\t1 - Add DVD" << endl;
	cout << "\t2 - Edit DVD" << endl;
	cout << "\t3 - Delete DVD" << endl;
	cout << "\t4 - Find DVD" << endl;
	cout << "\t5 - Print DVD" << endl;
	cout << "\t6 - Print All DVD's" << endl;
	cout << "\t0 - Return to Main Menu" << endl;
	cout << endl;
	cout << "Choose an option: ";
}


void PrintLoan()
{
	cout << endl;
	cout << "\tLOAN MENU" << endl;
	cout << "\t1 - Check Out Item" << endl;
	cout << "\t2 - Check In Item" << endl;
	cout << "\t3 - Print All Overdue Items" << endl;
	cout << "\t4 - Print All Patron Items" << endl;
	cout << "\t5 - Update Loan Status" << endl;
	cout << "\t6 - Re-check Item" << endl;
	cout << "\t7 - Report Lost" << endl;
	cout << "\t8 - Find Loan" << endl;
	cout << "\t0 - Return to Main Menu" << endl;
	cout << endl;
	cout << "Choose an option: ";
}

int main()
{
	bool running0, running1, running2, running3, running4, running5;
	int choice = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;
	int choice4 = -1;
	int choice5 = -1;

	int id;
	string title;
	

	patrons.LoadPatrons();
	items.LoadItems();
	loans.LoadLoans();

	while(running0)
	{
		cout << endl;
		PrintMain();

		cin >> choice;
		switch(choice)
		{
			case 1:
				PrintPatron();
				running1 = true;
				while(running1)
				{
					cin >> choice1;
					cin.ignore();
					switch (choice1)
					{
					case 1:
						cout << "\tADD PATRON" << endl;
						//cin.ignore();
						patrons.AddPatron();
						running1 = false;
						break;
					case 2:
						cout << "\tEDIT PATRON" << endl;
						patrons.EditPatron();
						running1 = false;
						break;
					case 3:
						cout << "\tDELETE PATRON" << endl;
						cout << endl;
						cout << "Enter ID of Patron to delete:" << endl;
						cin >> id; cin.ignore();
						patrons.DeletePatron(id);
						running1 = false;
						break;
					case 4:
						cout << "\tFIND PATRON BY ID" << endl;
						cout << endl;
						cout << "Enter ID of Patron to Find: ";
						cin >> id;
						cin.ignore();
						patrons.FindPatronID(id);
						running1 = false;
						break;
					case 5:
						cout << "\tPRINT PATRON" << endl;
						cout << endl;
						patrons.PrintPatron();
						running1 = false;
						break;
					case 6:
						cout << "\tPRINT ALL PATRONS" << endl;
						cout << endl;
						patrons.PrintAllPatrons();
						running1 = false;
						break;
					case 7:
						cout << "\tPAY FINES" << endl;
						patrons.PayFines();
						running1 = false;
						break;
					case 0:
						cout << "\tRETURN TO MAIN MENU" << endl;
						running1 = false;
						break;
					default:
						cout << "Invalid choice. Try again." << endl;
						break;
					}
				}
				break;
		//BOOK MENU
			case 2:
				PrintBook();
				running2 = true;
				while(running2)
				{
					cin >> choice2;
					cin.ignore();
					switch (choice2)
					{
					case 1:
						cout << "\tADD BOOK" << endl;
						//cin.ignore();
						items.AddItem(1);
						running2 = false;
						break;
					case 2:
						cout << "\tEDIT BOOK" << endl;
						items.EditItem(1);
						running2 = false;
						break;
					case 3:
						cout << "\tDELETE BOOK" << endl;
						cout << endl;
						cout << "Enter ID of Book to Delete:" << endl;
						cin >> id;
						cin.ignore();
						items.DeleteItem(id);
						running2 = false;
						break;
					case 4:
						cout << "\tFIND BOOK BY ID" << endl;
						cout << endl;
						cout << "Enter ID of Book to search: ";
						cin >> id;
						cin.ignore();
						items.FindItem(id);
						running2 = false;
						break;
					case 5:
						cout << "\tPRINT BOOK" << endl;
						cout << endl;
						items.Print(1);
						running2 = false;
						break;
					case 6:
						cout << "\tPRINT ALL BOOKS" << endl;
						cout << endl;
						items.PrintAllItems();
						running2 = false;
						break;
					case 0:
						cout << "\tRETURN TO MAIN MENU" << endl;
						running2 = false;
						break;
					default:
						cout << "Invalid choice. Try again." << endl;
						break;
					}
				}
				break;
		//DVD MENU
			case 3:
				PrintDVD();
				running5 = true;
				while (running5)
				{
					cin >> choice5;
					cin.ignore();
					switch (choice5)
					{
					case 1:
						cout << "\tADD DVD" << endl;
						//cin.ignore();
						items.AddItem(3);
						running5 = false;
						break;
					case 2:
						cout << "\tEDIT DVD" << endl;
						items.EditItem(3);
						running5 = false;
						break;
					case 3:
						cout << "\tDELETE DVD" << endl;
						cout << endl;
						cout << "Enter ID of DVD to Delete:" << endl;
						cin >> id;
						cin.ignore();
						items.DeleteItem(id);
						running5 = false;
						break;
					case 4:
						cout << "\tFIND DVD BY ID" << endl;
						cout << endl;
						cout << "Enter ID of DVD to search: ";
						cin >> id;
						cin.ignore();
						items.FindItem(id);
						running5 = false;
						break;
					case 5:
						cout << "\tPRINT DVD" << endl;
						cout << endl;
						items.Print(3);
						running5 = false;
						break;
					case 6:
						cout << "\tPRINT ALL DVD'S" << endl;
						cout << endl;
						items.PrintAllItems();
						running5 = false;
						break;
					case 0:
						cout << "\tRETURN TO MAIN MENU" << endl;
						running5 = false;
						break;
					default:
						cout << "Invalid choice. Try again." << endl;
						break;
					}
				}
				break;
		//AUDIO CD MENU
			case 4:
				PrintCD();
				running4 = true;
				while (running4)
				{
					cin >> choice4;
					cin.ignore();
					switch (choice4)
					{
					case 1:
						cout << "\tADD CD" << endl;
						//cin.ignore();
						items.AddItem(2);
						running4 = false;
						break;
					case 2:
						cout << "\tEDIT CD" << endl;
						items.EditItem(2);
						running4 = false;
						break;
					case 3:
						cout << "\tDELETE CD" << endl;
						cout << endl;
						cout << "Enter ID of CD to Delete:" << endl;
						cin >> id;
						cin.ignore();
						items.DeleteItem(id);
						running4 = false;
						break;
					case 4:
						cout << "\tFIND CD BY ID" << endl;
						cout << endl;
						cout << "Enter ID of CD to search: ";
						cin >> id;
						items.FindItem(id);
						running4 = false;
						break;
					case 5:
						cout << "\tPRINT CD" << endl;
						cout << endl;
						items.Print(2);
						running4 = false;
						break;
					case 6:
						cout << "\tPRINT ALL CD'S" << endl;
						cout << endl;
						items.PrintAllItems();
						running4 = false;
						break;
					case 0:
						cout << "\tRETURN TO MAIN MENU" << endl;
						running4 = false;
						break;
					default:
						cout << "Invalid choice. Try again." << endl;
						break;
					}
				}
				break;
		//LOAN MENU
			case 5:
				PrintLoan();
				running3 = true;
				while(running3)
				{
					cin >> choice3;
					switch (choice3)
					{
					case 1:
						cout << "\tCHECK OUT ITEM" << endl;
						loans.AddLoan();
						running3 = false;
						break;
					case 2:
						cout << "\tCHECK IN ITEM" << endl;
						cout << endl;
						cout << "Enter ID of Loan: " << endl;
						cin >> id;
						loans.DeleteLoan(id);
						running3 = false;
						break;
					case 3:
						cout << "\tPRINT ALL OVERDUE" << endl;
						loans.PrintOverdue();
						running3 = false;
						break;
					case 4:
						cout << "\tPRINT ALL PATRON ITEMS" << endl;
						cout << endl;
						loans.PrintLoansAll();
						running3 = false;
						break;
					case 5:
						cout << "\tUPDATE LOAN STATUS" << endl;
						loans.UpdateStatus();
						running3 = false;
						break;
					case 6:
						cout << "\tRE-CHECK ITEM" << endl;
						loans.EditLoan();
						running3 = false;
						break;
					case 7:
						cout << "\tREPORT LOST" << endl;
						cout << endl;
						loans.ReportLost();
						running3 = false;
						break;
					case 8:
						cout << "\tFIND LOAN" << endl;
						cout << endl;
						cout << "Enter ID of Loan to search: ";
						cin >> id;
						loans.FindLoan(id);
						running3 = false;
						break;
					case 0:
						cout << "\tRETURN TO MAIN MENU" << endl;
						running3 = false;
						break;
					default:
						cout << "Invalid choice. Try again." << endl;
						break;
					}
				}
				break;
			case 0:
				running0 = false;
				running1 = false;
				running2 = false;
				running3 = false;
				running4 = false;
				running5 = false;
				cout << "Exiting." << endl;
				break;
			default:
				cout << "Invalid choice. Try again." << endl;
		}

	}


	items.StoreItems();
	patrons.StorePatrons();
	loans.StoreLoans();
	items.Cleanup();
	patrons.Cleanup();
	loans.CleanUp();

	return 0;
}
