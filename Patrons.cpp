#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include "Patron.h"
#include "Patrons.h"
using namespace std;

Patrons::Patrons()
{
	patronCount = 0;
}

void Patrons::iCounter() { patronCount++;}
void Patrons::dCounter() { patronCount--;}
int Patrons::getCount() { return patronCount;}

void Patrons::AddPatron()
{
	int id;
	string name;
	float balance = 0.00;
	int booksOut = 0;
	Patron* temp;

	bool running = true;
	bool lock = true;

	cout << "Enter new patron name: ";
	//cin.ignore();
	getline(cin, name);
	cout << "Enter the new patron's 6-digit ID: ";

	while (running)
	{
		cin >> id;
		if (id < 100000)
		{
			cout << "Not a 6 digit number, please try again." << endl;
		}
		else if (id > 999999)
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
	
	temp = new Patron(name, id, balance, booksOut);

	patronList.push_back(temp);
	iCounter();
}

void Patrons::DeletePatron(int id)
{
	Patron* temp;
	for (auto it = patronList.begin(); it != patronList.end(); ++it)
	{
		if ((*it)->GetID() == id)
		{
			it = patronList.erase(it);
			break;
		}
	}
	dCounter();
	return;
}

void Patrons::EditPatron()
{
	int id;

	cout << "Enter ID of Patron to Edit: ";
	cin >> id;
	cout << "Enter new ID for Patron: ";
	for (int i = 0; i < patronCount; ++i)
	{
		if (patronList[i]->GetID() == id)
		{
			cin >> id;
			if (patronList[i]->GetID() == id)
			{
				cout << "ID already in use. Try again." << endl;
				--i;
			}
			else {
				patronList[i]->SetID(id);
			}
		}
	}
}

Patron* Patrons::FindPatronID(int id)
{
	Patron *temp;
	for (auto it = patronList.begin(); it != patronList.end(); ++it)
	{
		temp = *it;
		if ((*it)->GetID() == id)
		{
			cout << "Patron Name: " << temp->GetName() << "\nPatron ID: " << temp->GetID() << "\nPatron Balance: " << temp->GetBalance() << "\nPatron Books Out: " << temp->GetBooksOut() << endl;
		}
	}
}

void Patrons::PrintAllPatrons()
{
	Patron* temp;
	for (auto it = patronList.begin(); it != patronList.end(); ++it)
	{
		temp = *it;
		cout << "Patron Name: " << temp->GetName() << "\nPatron ID: " << temp->GetID() << "\nPatron Balance: " << temp->GetBalance() << "\nPatron Books Out: " << temp->GetBooksOut() << endl;
		cout << endl;
	}
}

void Patrons::PrintPatron()
{
	Patron *temp;
	int id;

	cout << "Enter ID of Patron to print: ";
	cin >> id;

	for (int i = 0; i < patronCount; ++i)
	{
		if (patronList[i]->GetID() == id)
		{
			cout << "Name: " << patronList[i]->GetName() << "\nID: " << id << "\nBalance: " << patronList[i]->GetBalance() << "\nBooks Out: " << patronList[i]->GetBooksOut() << endl;
		}
	}
}

void Patrons::PayFines()
{
	cout << "Function not implemented." << endl;
}

//----------------------------------------------------------------------------------------------
void Patrons::StorePatrons()
{
	ofstream fout;
	fout.open("patrons.dat");
	fout << patronCount << endl;

	Patron *temp;
	for (auto it = patronList.begin(); it != patronList.end(); ++it)
	{
		temp = *it;
		fout << temp->GetName() << " " << temp->GetID() << " " << temp->GetBalance() << " " << temp->GetBooksOut() << endl;
	}
	fout.close();
}
void Patrons::LoadPatrons()
{
	ifstream fin;
	string name, last;
	int idNum;
	float balance;
	int booksOut;
	fin.open("patrons.dat");
	fin >> patronCount; fin.ignore();

	for (int i = 0; i < patronCount; i++)
	{	
		getline(fin, name, ' ');
		getline(fin, last, ' ');
		name.append(1, ' ');
		name += last;
		fin >> idNum;
		fin >> balance;
		fin >> booksOut; fin.ignore();
		patronList.push_back(new Patron(name, idNum, balance, booksOut));
	}
	fin.close();
}

void Patrons::Cleanup()
{
	for (auto it = patronList.begin(); it != patronList.end(); ++it)
	{
		delete* it;
	}
	patronList.clear();
}