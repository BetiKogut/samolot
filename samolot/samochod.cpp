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
	out << "Przebieg: " << samochod.przebieg << endl;
	return out;
}

istream& operator >> (istream& s, Samochod &samochod)
{
	s >> samochod.numer;
	return s;
}

void Samochod::zapisz_samochod(string nazwa) {
#ifdef _DEBUG  
	cout << "Zapisano obiekt Samochod" << endl;
#endif
	(*this).zapisz_srodek(nazwa);
	fstream plik;
	plik.open(nazwa);
	plik.seekg(0, ios::end);
	plik << *this;
	plik.close();

}

Samochod :: ~Samochod()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Samochod" << endl;
#endif
}