#include <iostream>
#include <string>
#include <fstream>
#include "samochod.h"

using namespace std;

Samochod::Samochod() {
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor Samochod" << endl;
#endif
	numer = 2345;
	ilosc_miejsc = 5;
	przebieg = 100000;
}


ostream& operator << (ostream& out, Samochod& samochod)
{
	out << "Numer samolotu: " << samochod.numer << endl << "Ilosc miejsc: " << samochod.ilosc_miejsc << endl << "Przebieg: " << samochod.przebieg << endl;
	return out;
}

istream& operator >> (istream& s, Samochod &samochod)
{
	s >> samochod.numer;
	return s;
}

void Samochod::zapisz() {
#ifdef _DEBUG  
	cout << "Zapisano obiekt Samochod" << endl;
#endif
	ofstream plik("samochod.txt");
	plik << *this;
	plik.close();

}

Samochod :: ~Samochod()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Samochod" << endl;
#endif
}