#include "Book.h"
using namespace std;

Book::Book()
{
	Author = "None";
	Title = "None";
	ISBN = "None";
	Category = "None";
}

Book::Book(int id, float cost, int status, int loanperiod, string author, string title, string isbn, string category)
{
	ID = id;
	Cost = cost;
	Status = status;
	LoanPeriod = loanperiod;
	Author = author;
	Title = title;
	ISBN = isbn;
	Category = category;
}
//Sets
void Book::SetAuthor(string author){
	Author = author;
}
void Book::SetTitle(string title){
	Title = title;
}
void Book::SetISBN(string isbn){
	ISBN = isbn;
}
void Book::SetCategory(string category) {
	Category = category;
}
//Gets
string Book::GetAuthor() { return Author; }
string Book::GetTitle() { return Title; }
string Book::GetISBN() { return ISBN; }
string Book::GetCategory() { return Category; }
//-----------------------------------------------------
void Book::Print() {
	cout << "Book ID: " << ID << endl;
	cout << "Book Cost: " << Cost << endl;
	cout << "Book Status: " << Status << endl;
	cout << "Book Loan Period: " << LoanPeriod << endl;
	cout << "Book Title: " << Title << endl;
	cout << "Book Author: " << Author << endl;
	cout << "Book ISBN: " << ISBN << endl;
	cout << "Book Category: " << Category << endl;
	cout << endl;
}

int Book::RawPrint(int type) {
	cout << type << " " << ID << " " << Cost << " " << Status << " " << LoanPeriod << " ";
	cout << Title << " " << Author << " " << ISBN << " " << Category << endl;
}
