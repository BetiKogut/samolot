#include <iostream>
#include <string>
#include <fstream>
#include "dane_samolotu.h"

using namespace std;

//konstruktor
DaneSamolotu :: DaneSamolotu()
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor DaneSamolotu" << endl;
#endif

	start = "Warszawa";
	cel = "Berlin";
}

DaneSamolotu & DaneSamolotu :: operator = (const DaneSamolotu &dane)
{
	if (this != &dane)
	{
		start = dane.start;
		cel = dane.cel;

		return *this;
	}
	else
		cout << "Nie mozna uzyc operatora = do tych samych danych!";
	
}

void DaneSamolotu :: zmiendane(string nowystart, string nowycel)
{
	start = nowystart;
	cel = nowycel;
}

void DaneSamolotu::zwrocdane()
{
	cout << "Start: " << start << endl;
	cout << "Cel: " << cel << endl;
}

ostream& operator << (ostream& out, DaneSamolotu& dane)
{
	out << dane.start << " " << dane.cel << endl;
	return out;
}

istream& operator >> (istream& s, DaneSamolotu &dane)
{
	cout << "Wpisz start lotu: ";
	s >> dane.start;
	cout << endl << "Wpisz cel lotu: ";
	s >> dane.cel;
	cout << endl;

	return s;
}

//destruktor
DaneSamolotu::~DaneSamolotu()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~DaneSamolotu" << endl;
#endif
}