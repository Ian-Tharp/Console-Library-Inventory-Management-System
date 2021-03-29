makefile : Patron.o LibraryItem.o Book.o Cd.o DvD.o Loan.o Patrons.o LibraryItems.o Loans.o main.o
	g++ Patron.o LibraryItem.o Book.o Cd.o Loan.o Patrons.o LibraryItems.o Loans.o main.o -o makefile
Patron.o : Patron.h
	g++ -c Patron.cpp
LibraryItem.o : LibraryItem.h
	g++ -c LibraryItem.cpp
Book.o : Book.h
	g++ -c Book.cpp
Cd.o : Cd.h
	g++ -c Cd.cpp
DvD.o : DvD.h
	g++ -c DvD.cpp
Loan.o : Loan.h
	g++ -c Loan.cpp
Patrons.o : Patron.h Patrons.h
	g++ -c Patrons.cpp
LibraryItems.o : LibraryItem.h LibraryItems.h
	g++ -c LibraryItems.cpp
Loans.o : Loan.h Loans.h Book.h Patron.h
	g++ -c Loans.cpp
main.o : Patron.h Patrons.h LibraryItem.h LibraryItems.h Cd.h DvD.h Book.h Loan.h Loans.h
	g++ -c main.cpp
clean :
	rm *.o makefile
