#ifndef DVD_H
#define DVD_H

#include "LibraryItem.h"
#include <string>
#include <time.h>
using namespace std;

class DvD : public LibraryItem {
	public:
		DvD();
		DvD(int id, float cost, int status, int loanperiod, string title, string category, string studio, float runtime,  time_t releasedate);

		void Print();
		int RawPrint(int type);

		//Sets
		void SetTitle(string title);
		void SetCategory(string category);
		void SetRunTime(float runtime);
		void SetStudio(string studio);
		void SetReleaseDate(time_t releasedate);
		//Gets
		string GetTitle();
		string GetCategory();
		float GetRunTime();
		string GetStudio();
		time_t GetReleaseDate();

	private:
		string Title;
		string Category;
		float RunTime;
		string Studio;
		time_t ReleaseDate;
};

#endif