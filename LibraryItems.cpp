#include "LibraryItem.h"
#include "LibraryItems.h"
#include "Book.h"
#include "Cd.h"
#include "DvD.h"
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

LibraryItems::LibraryItems() {
	itemsCount = 0;
}
//Counter
void LibraryItems::iCounter() {
	itemsCount++;
}
void LibraryItems::dCounter() {
	itemsCount--;
}
int LibraryItems::getCount() {
	return itemsCount;
}
//-------------------------------------
void LibraryItems::StoreItems() {
	ofstream fout;
	fout.open("items.dat");
	fout << itemsCount << endl;

	LibraryItem* temp;
	for (auto it = itemsList.begin(); it != itemsList.end(); ++it)
	{
		temp = *it;
		fout << temp->GetID() << " " << temp->GetCost() << " " << temp->GetStatus() << " " << temp->GetLoanPeriod() << endl;
		
		if (typeid(**it) == typeid (Book))
		{
			Book* book = dynamic_cast<Book*> (*it);
			fout << book->RawPrint(1);
			//fout << "1 " << book->GetAuthor() << " " << book->GetTitle() << " " << book->GetISBN() << " " << book->GetCategory() << endl;
		}
		else if (typeid(**it) == typeid (CD))
		{
			CD* cd = dynamic_cast<CD*> (*it);
			fout << cd->RawPrint(2);
			//fout << "2 " << cd->GetArtist() << " " << cd->GetTitle() << " " << cd->GetGenre() << " " << cd->GetTracks() << " " << cd->GetReleaseDate() << endl;
		}
		else
		{
			DvD* dvd = dynamic_cast<DvD*> (*it);
			fout << dvd->RawPrint(3);
			//fout << "3 " << dvd->GetTitle() << " " << dvd->GetCategory() << " " << dvd->GetStudio() << " " << dvd->GetRunTime() << " " << dvd->GetReleaseDate() << endl;
		}
	}
	fout.close();
}

void LibraryItems::LoadItems() {
	ifstream fin;
	string author, title, isbn, category, artist, genre, studio;
	int id, loanperiod, status, itemtype, tracks;
	float cost, runtime;
	time_t releasedate;

	fin.open("items.dat");
	fin >> itemsCount; fin.ignore();

	for (int i = 0; i < itemsCount; i++)
	{
		fin >> itemtype;
		fin >> id;
		fin >> cost;
		fin >> status;
		fin >> loanperiod;
		fin.ignore();

		if (itemtype == 1)
		{
			getline(fin, title);
			getline(fin, author);
			getline(fin, isbn);
			getline(fin, category);
			fin.ignore();

			itemsList.push_back(new Book(id, cost, status, loanperiod, title, author, isbn, category));
		}
		else if (itemtype == 2)
		{
			getline(fin, artist);
			getline(fin, title);
			getline(fin, genre);
			fin >> tracks;
			fin >> releasedate;
			fin.ignore();

			itemsList.push_back(new CD(id, cost, status, loanperiod, artist, title, genre, tracks, releasedate));
		}
		else if (itemtype == 3)
		{
			getline(fin, title);
			getline(fin, category);
			getline(fin, studio);
			fin >> runtime;
			fin >> releasedate;
			fin.ignore();

			itemsList.push_back(new DvD(id, cost, status, loanperiod, title, category, studio, runtime, releasedate));
		}
	}
	fin.close();
}

void LibraryItems::Cleanup()
{
	for (auto it = itemsList.begin(); it != itemsList.end(); ++it)
	{

		delete* it;
	}
	itemsList.clear();
}
//---------------------------------------------------------------------------------------------
int LibraryItems::AddItem(int item)
{
	string author, title, isbn, category, artist, genre, studio;
	int id, loanperiod, status, itemtype, tracks, choice;
	float cost, runtime;
	bool running;
	time_t releasedate;
	LibraryItem* temp;

	cout << "Enter new item ID: ";
	cin >> choice;
	cout << "Enter cost for new item: ";
	cin >> cost;
	cin.ignore();
	if (item == 1)
	{
		cout << "Enter the Title of the Book: ";
		getline(cin, title);
		cout << "Enter the Author of the Book: ";
		getline(cin, author);
		cout << "Enter the ISBN of the Book (no spaces): ";
		getline(cin, isbn);
		cout << "Enter the Category of the Book: ";
		getline(cin, category);

		status = 3;
		loanperiod = 1;
		temp = new Book(id, cost, status, loanperiod, author, title, isbn, category);
		running = false;
	}
	else if (item == 2)
	{
		cout << "Enter the Title of the CD: ";
		getline(cin, title);
		cout << "Enter the Artist of the CD: ";
		getline(cin, artist);
		cout << "Enter the Genre of the CD: ";
		getline(cin, genre);
		cout << "Enter the # of Tracks: ";
		cin >> tracks;
		cin.ignore();
			
		status = 3;
		loanperiod = 1;
		temp = new CD(id, cost, status, loanperiod, artist, title, genre, tracks, releasedate);
		running = false;
		}
	else
	{
		cout << "Enter the Title of the DVD: ";
		getline(cin, title);
		cout << "Enter the Category of the DVD: ";
		getline(cin, category);
		cout << "Enter the Studio of the DVD: ";
		getline(cin, studio);
		cout << "Enter the total Run Time: ";
		cin >> runtime;
		cin.ignore();

		status = 3;
		loanperiod = 1;
		temp = new DvD(id, cost, status, loanperiod, title, category, studio, runtime, releasedate);
		running = false;
	}
	iCounter();
}
int LibraryItems::DeleteItem(int id)
{
	LibraryItem* temp;
	for (auto it = itemsList.begin(); it != itemsList.end(); ++it)
	{
		if ((*it)->GetID() == id)
		{
			it = itemsList.erase(it);
			break;
		}
	}
	dCounter();
}
int LibraryItems::EditItem(int id)
{
	int itemid;
	float cost;
	LibraryItem* temp;

	for (auto it = itemsList.begin(); it != itemsList.end(); ++it)
	{
		temp = *it;
		if (id == 1) //Book
		{
			cout << "Enter ID of Book to Edit: ";
			cin >> itemid;
			for (int i = 0; i < itemsCount; ++i)
			{
				if (temp->GetID() == itemid)
				{
					cout << "Enter new price for Book: ";
					cin >> cost;
					temp->SetCost(cost);
					cout << "Price updated." << endl;
				}
				else {
					cout << "No matching ID found." << endl;
					break;
				}
			}
		}
		else if (id == 2) //CD
		{
			cout << "Enter ID of CD to Edit: ";
			cin >> itemid;
			for (int i = 0; i < itemsCount; ++i)
			{
				if (temp->GetID() == itemid)
				{
					cout << "Enter new price for CD: ";
					cin >> cost;
					temp->SetCost(cost);
					cout << "Price updated." << endl;
				}
				else {
					cout << "No matching ID found." << endl;
					break;
				}
			}
		}
		else if (id == 3)//DVD
		{
			cout << "Enter ID of DVD to Edit: ";
			cin >> itemid;
			for (int i = 0; i < itemsCount; ++i)
			{
				if (temp->GetID() == itemid)
				{
					cout << "Enter new price for DVD: ";
					cin >> cost;
					temp->SetCost(cost);
					cout << "Price updated." << endl;
				}
				else {
					cout << "No matching ID found." << endl;
					break;
				}
			}
		}
	}
}
void LibraryItems::PrintAllItems()
{
	for (auto it = itemsList.begin(); it != itemsList.end(); ++it)
	{
		cout << "ID: " << (*it)->GetID() << " Cost: " << (*it)->GetCost() << " Status: " << (*it)->GetStatus() << " Loan Period: " << (*it)->GetLoanPeriod() << endl;
		
		if (typeid (**it) == typeid (Book))
		{
			Book* book = dynamic_cast<Book*> (*it);
			cout << "Author: " << book->GetAuthor() << endl;
			cout << "Title: " << book->GetTitle() << endl;
			cout << "ISBN: " << book->GetISBN() << endl;
			cout << "Category: " << book->GetCategory() << endl;
		}
		else if (typeid(**it) == typeid (CD))
		{
			CD* cd = dynamic_cast<CD*> (*it);
			cout << "Title: " << cd->GetTitle() << endl;
			cout << "Artist: " << cd->GetArtist() << endl;
			cout << "Genre: " << cd->GetGenre() << endl;
			cout << "Tracks" << cd->GetTracks() << endl;
			cout << "Release Date: " << cd->GetReleaseDate() << endl;
		}
		else
		{
			DvD* dvd = dynamic_cast<DvD*> (*it);
			cout << "Title: " << dvd->GetTitle() << endl;
			cout << "Category: " << dvd->GetCategory() << endl;
			cout << "Studio: " << dvd->GetStudio() << endl;
			cout << "Run Time: " << dvd->GetRunTime() << endl;
			cout << "Release Date: " << dvd->GetReleaseDate() << endl;
		}
		cout << endl;
	}
}
LibraryItem* LibraryItems::FindItem(int id)
{
	LibraryItem* temp;
	for (auto it = itemsList.begin(); it != itemsList.end(); ++it)
	{
		temp = *it;
		if (temp->GetID() == id)
		{
			cout << "ID: " << temp->GetID() << endl;
			cout << "Cost: " << temp->GetCost() << endl;
			cout << "Status: " << temp->GetStatus() << endl;
			cout << "Loan Period: " << temp->GetLoanPeriod() << endl;

			if (typeid (**it) == typeid (Book))
			{
				Book* book = dynamic_cast<Book*> (*it);
				cout << "Author: " << book->GetAuthor() << endl;
				cout << "Title: " << book->GetTitle() << endl;
				cout << "ISBN: " << book->GetISBN() << endl;
				cout << "Category: " << book->GetCategory() << endl;
			}
			else if (typeid(**it) == typeid (CD))
			{
				CD* cd = dynamic_cast<CD*> (*it);
				cout << "Title: " << cd->GetTitle() << endl;
				cout << "Artist: " << cd->GetArtist() << endl;
				cout << "Genre: " << cd->GetGenre() << endl;
				cout << "Tracks" << cd->GetTracks() << endl;
				cout << "Release Date: " << cd->GetReleaseDate() << endl;
			}
			else
			{
				DvD* dvd = dynamic_cast<DvD*> (*it);
				cout << "Title: " << dvd->GetTitle() << endl;
				cout << "Category: " << dvd->GetCategory() << endl;
				cout << "Studio: " << dvd->GetStudio() << endl;
				cout << "Run Time: " << dvd->GetRunTime() << endl;
				cout << "Release Date: " << dvd->GetReleaseDate() << endl;
			}
		}
		else {
			cout << "No matching ID found." << endl;
		}
	}
}
int LibraryItems::Print(int type)
{
	int id;

	cout << "Enter ID of Item to print: ";
	cin >> id;

	for (auto it = itemsList.begin(); it != itemsList.end(); ++it)
	{
		if ((*it)->GetID() == id)
		{
			cout << "ID: " << (*it)->GetID() << endl;
			cout << "Cost: " << (*it)->GetCost() << endl;
			cout << "Status: " << (*it)->GetStatus() << endl;
			cout << "Loan Period: " << (*it)->GetLoanPeriod() << endl;

			if (type == 1)
			{
				Book* book = dynamic_cast<Book*> (*it);
				cout << "Author: " << book->GetAuthor() << endl;
				cout << "Title: " << book->GetTitle() << endl;
				cout << "ISBN: " << book->GetISBN() << endl;
				cout << "Category: " << book->GetCategory() << endl;
			}
			else if (type == 2)
			{
				CD* cd = dynamic_cast<CD*> (*it);
				cout << "Title: " << cd->GetTitle() << endl;
				cout << "Artist: " << cd->GetArtist() << endl;
				cout << "Genre: " << cd->GetGenre() << endl;
				cout << "Tracks" << cd->GetTracks() << endl;
				cout << "Release Date: " << cd->GetReleaseDate() << endl;
			}
			else if (type == 3)
			{
				DvD* dvd = dynamic_cast<DvD*> (*it);
				cout << "Title: " << dvd->GetTitle() << endl;
				cout << "Category: " << dvd->GetCategory() << endl;
				cout << "Studio: " << dvd->GetStudio() << endl;
				cout << "Run Time: " << dvd->GetRunTime() << endl;
				cout << "Release Date: " << dvd->GetReleaseDate() << endl;
			}
		}
		else {
			cout << "No matching ID to print." << endl;
		}
	}
}