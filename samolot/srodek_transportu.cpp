#include <iostream>
#include <string>
#include <fstream>
#include "srodek_transportu.h"

using namespace std;

Srodek_transportu :: Srodek_transportu() {
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor Srodek_transportu" << endl;
#endif
	
}

///Zdefiniowany operator strumieniowy
ostream& operator << (ostream &s, Srodek_transportu &srodek_transportu) {
	s << srodek_transportu.numer << endl << srodek_transportu.ilosc_miejsc << endl;
	return s;
}

///Zdefiniowany operator strumieniowy
istream& operator >> (istream& s, Srodek_transportu &srodek_transportu) {
	s >> srodek_transportu.numer >> srodek_transportu.ilosc_miejsc;
	return s;
}

void Srodek_transportu::zapisz_srodek(string nazwa) {
#ifdef _DEBUG  
	cout << "Zapisano dane Srodek" << endl;
#endif
	ofstream plik(nazwa);
	plik << *this;
	plik.close();

}

void Srodek_transportu::wczytaj_srodek(string nazwa) {
#ifdef _DEBUG  
	cout << "Wczytano obiekt Srodek" << endl;
#endif
	fstream plik(nazwa);
	plik >> *this;
	plik.close();

}

Srodek_transportu :: ~Srodek_transportu()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Srodek_transportu" << endl;
#endif
}