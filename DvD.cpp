#include "DvD.h"
using namespace std;

DvD::DvD()
{
	Title = "";
	Category = "";
	Studio = "";
	RunTime = 0.00;
	ReleaseDate = 0;
}
DvD::DvD(int id, float cost, int status, int loanperiod, string title, string category, string studio, float runtime, time_t releasedate)
{
	ID = id;
	Cost = cost;
	Status = status;
	LoanPeriod = loanperiod;
	Title = title;
	Category = category;
	Studio = studio;
	RunTime = runtime;
	ReleaseDate = releasedate;
}
//Sets
void DvD::SetCategory(string category) {
	Category = category;
}
void DvD::SetReleaseDate(time_t releasedate) {
	ReleaseDate = releasedate;
}
void DvD::SetRunTime(float runtime) {
	RunTime = runtime;
}
void DvD::SetStudio(string studio) {
	Studio = studio;
}
void DvD::SetTitle(string title) {
	Title = title;
}

//Gets
string DvD::GetCategory() { return Category; }
time_t DvD::GetReleaseDate() { return ReleaseDate; }
float DvD::GetRunTime() { return RunTime; }
string DvD::GetStudio() { return Studio; }
string DvD::GetTitle() { return Title; }

//Print
void DvD::Print()
{
	cout << "DVD ID: " << ID << endl;
	cout << "DVD Cost: " << Cost << endl;
	cout << "DVD Status: " << Status << endl;
	cout << "DVD Loan Period: " << LoanPeriod << endl;
	cout << "DVD Title: " << Title << endl;
	cout << "DVD Category: " << Category << endl;
	cout << "DVD Studio: " << Studio << endl;
	cout << "DVD Release Date: " << ReleaseDate << endl;
	cout << "DVD Run Time: " << RunTime << endl;
}

int DvD::RawPrint(int type)
{
	cout << type << " " << ID << " " << Cost << " " << Status << " " << LoanPeriod << " ";
	cout << Title << " " << Category << " " << Studio << " " << RunTime << " " << ReleaseDate << endl;
}