#ifndef CD_H
#define CD_H

#include "LibraryItem.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class CD : public LibraryItem {
	public:
		CD();
		CD(int id, float cost, int status, int loanperiod, string artist, string title, string genre, int tracks, time_t releasedate);

		//Sets
		void SetArtist(string artist);
		void SetTitle(string title);
		void SetTracks(int tracks);
		void SetReleaseDate(time_t releasedate);
		void SetGenre(string genre);

		void Print();
		int RawPrint(int type);

		//Gets
		string GetArtist();
		string GetTitle();
		int GetTracks();
		time_t GetReleaseDate();
		string GetGenre();

	private:
		string Artist;
		string Title;
		int Tracks;
		time_t ReleaseDate;
		string Genre;
};

#endif