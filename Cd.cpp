#include "Cd.h"
using namespace std;

CD::CD() {
	Artist = "";
	Title = "";
	Tracks = 0;
	ReleaseDate = 0;
	Genre = "";
}
CD::CD(int id, float cost, int status, int loanperiod, string artist, string title, string genre, int tracks, time_t releasedate)
{
	ID = id;
	Cost = cost;
	Status = status;
	LoanPeriod = loanperiod;
	Artist = artist;
	Title = title;
	Tracks = tracks;
	ReleaseDate = releasedate;
	Genre = genre;
}
//Sets
void CD::SetArtist(string artist) {
	Artist = artist;
}
void CD::SetGenre(string genre) {
	Genre = genre;
}
void CD::SetReleaseDate(time_t releasedate) {
	ReleaseDate = releasedate;
}
void CD::SetTitle(string title) {
	Title = title;
}
void CD::SetTracks(int tracks) {
	Tracks = tracks;
}
//Gets
string CD::GetArtist() { return Artist; }
string CD::GetGenre() { return Genre; }
time_t CD::GetReleaseDate() { return ReleaseDate; }
string CD::GetTitle() { return Title; }
int CD::GetTracks() { return Tracks; }

//Print
void CD::Print() {
	cout << "CD ID: " << ID << endl;
	cout << "CD Cost: " << Cost << endl;
	cout << "CD Status: " << Status << endl;
	cout << "CD Loan Period: " << LoanPeriod << endl;
	cout << "CD Title: " << Title << endl;
	cout << "CD Artist: " << Artist << endl;
	cout << "CD Genre: " << Genre << endl;
	cout << "CD # of Tracks: " << Tracks << endl;
	cout << "CD Release Date: " << ReleaseDate << endl;
}
int CD::RawPrint(int type) {
	cout << type << " " << ID << " " << Cost << " " << Status << " " << LoanPeriod << " ";
	cout << Title << " " << Artist << " " << Genre << " " << Tracks << " " << ReleaseDate << endl;
}