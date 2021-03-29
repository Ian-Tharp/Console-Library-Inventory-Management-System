#include "Patron.h"
using namespace std;

Patron::Patron(){
	Name = "none";
	idNum = -1;
	fineBalance = 0.00;
	numBooksOut = 0;
}

Patron::Patron(string name, int id, float balance, int booksOut){
	Name = name;
	idNum = id;
	fineBalance = balance;
	numBooksOut = booksOut;
}

//Sets
void Patron::SetName(string name)
{
	Name = name;
}
void Patron::SetID(int id)
{
	idNum = id;
}
void Patron::SetFineBalance(float balance)
{
	fineBalance = balance;
}
void Patron::SetCurrentBooksOut(int booksOut)
{
	numBooksOut = booksOut;
}
//Gets
string Patron::GetName() {return Name;}
int Patron::GetID() {return idNum;}
float Patron::GetBalance() {return fineBalance;}
int Patron::GetBooksOut() {return numBooksOut;}