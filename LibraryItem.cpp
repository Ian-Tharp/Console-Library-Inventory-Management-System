#include "LibraryItem.h"
using namespace std;

LibraryItem::LibraryItem()
{
	ID = 0;
	Cost = 0.00;
	Status = 0;
	LoanPeriod = 0;
}
LibraryItem::LibraryItem(int id, float cost, int status, int loanperiod)
{
	ID = id;
	Cost = cost;
	Status = status;
	LoanPeriod = loanperiod;
}
//Sets
void LibraryItem::SetID(int id) {
	ID = id;
}
void LibraryItem::SetCost(float cost) {
	Cost = cost;
}
void LibraryItem::SetStatus(int status) {
	Status = status;
}
void LibraryItem::SetLoanPeriod(int loanperiod) {
	LoanPeriod = loanperiod;
}
//Gets
int LibraryItem::GetID() { return ID; }
float LibraryItem::GetCost() { return Cost; }
int LibraryItem::GetStatus() { return Status; }
int LibraryItem::GetLoanPeriod() { return LoanPeriod; }
//Print
int LibraryItem::Print(int type) {
	cout << "ID Number: " << ID << endl;
	cout << "Cost: " << Cost << endl;
	cout << "Status: " << Status << endl;
	cout << "Loan Period: " << LoanPeriod << endl;
}
int LibraryItem::RawPrint(int type) {
	cout << type << " " << ID << " " << Cost << " " << Status << " " << LoanPeriod << endl;
}
ostream& operator<<(ostream& st, LibraryItem& li) {
	int type;
	li.RawPrint(type);
	return st;
}