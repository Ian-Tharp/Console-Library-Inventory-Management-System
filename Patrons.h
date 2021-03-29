#ifndef PATRONS_H
#define PATRONS_H

#include <vector>
using namespace std;

class Patrons {
	public:
		Patrons();
		//Functions
		void AddPatron();
		void EditPatron();
		void DeletePatron(int);
		Patron* FindPatronID(int);
		void PrintPatron();
		void PrintAllPatrons();
		void PayFines();

		//Counter
		void iCounter();
		void dCounter();
		int getCount();
		//Data Load/Store
		void StorePatrons();
		void LoadPatrons();
		void Cleanup();

	private:
		int patronCount;
		typedef vector<Patron*> patronType;
		patronType patronList;
};

#endif
