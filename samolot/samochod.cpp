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
	out << *((Srodek_transportu*)(&samochod));
	out << samochod.przebieg << endl;
	return out;
}

istream& operator >> (istream& s, Samochod &samochod)
{
	s >> *((Srodek_transportu*)(&samochod));
	s >> samochod.przebieg;
	return s;
}

void Samochod::zapisz_samochod(string nazwa) {
#ifdef _DEBUG  
	cout << "Zapisano dane Samochod" << endl;
#endif
	ofstream plik;
	plik.open(nazwa);
	plik << *this;
	plik.close();

}

void Samochod::wczytaj_samochod(string nazwa) {
#ifdef _DEBUG  
	cout << "Wczytano obiekt Samochod" << endl;
#endif
	/*string smietnik;
	ifstream plik(nazwa);
	for (int i = 0; i < 2; i++)
	{
		getline(plik, smietnik);
	}*/
	ifstream plik;
	plik.open(nazwa);
	plik >> *this;
	plik.close();

}

void Samochod :: wypisz_stan()
{
	cout << "Uruchomiono funkcje wypisz z klasy samochod:" << endl;
	cout << (*this).numer << endl << (*this).ilosc_miejsc << endl << (*this).przebieg << endl;
}

Samochod :: ~Samochod()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Samochod" << endl;
#endif
}