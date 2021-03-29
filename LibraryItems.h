#ifndef LIBRARYITEMS_H
#define LIBRARYITEMS_H
#include "LibraryItem.h"
#include <vector>
using namespace std;

class LibraryItems {
	public:
		LibraryItems();
		LibraryItems(int id, float cost, int status, int loanperiod, string author, string title, string isbn, string category);
		LibraryItems(int id, float cost, int status, int loanperiod, string artist, string title, string genre, int tracks, time_t releasedate);
		LibraryItems(int id, float cost, int status, int loanperiod, string title, string category, string studio, float runtime, time_t releasedate);
		//Functions
		int AddItem(int item);
		int EditItem(int id);
		int DeleteItem(int id);
		int Print(int type);
		void PrintAllItems();
		LibraryItem* FindItem(int id);
		
		//Load/Store data
		void StoreItems();
		void LoadItems();
		void Cleanup();
		//Counter
		void iCounter();
		void dCounter();
		int getCount();

	private:
		vector<LibraryItem*> itemsList;
		int itemsCount;
};

#endif