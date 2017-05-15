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

ostream& operator << (ostream &out, Srodek_transportu &srodek_transportu) 
{
	out << srodek_transportu.wektor_pasazerow.size() << endl;
	for (int i = 0; i < srodek_transportu.wektor_pasazerow.size(); i++)
	{
		out << srodek_transportu.wektor_pasazerow[i];
	}
	out << srodek_transportu.numer << endl << srodek_transportu.ilosc_miejsc << endl;
	return out;
}

istream& operator >> (istream& s, Srodek_transportu &srodek_transportu) 
{
	int size;
	s >> size;
	srodek_transportu.wektor_pasazerow.clear();
	for (int i = 0; i < size; i++)
	{
		Pasazerowie pasazer;
		s >> pasazer;
		srodek_transportu.wektor_pasazerow.push_back(pasazer);

	}
	s >> srodek_transportu.numer >> srodek_transportu.ilosc_miejsc;
	return s;
}

void Srodek_transportu::zapisz_srodek(string nazwa) 
{
	ofstream plik;
	plik.exceptions(ifstream::failbit | ifstream::badbit);
	try
	{
		plik.open(nazwa);
	}
	catch (ifstream::failure)
	{
		cout << "!nie mozna otworzyc pliku!" << endl;
		return;
	}
#ifdef _DEBUG  
	cout << "Zapisano dane Srodek" << endl;
#endif
	plik << *this;
	plik.close();
}

void Srodek_transportu::wczytaj_srodek(string nazwa) 
	{
		ifstream plik;
		plik.exceptions(ifstream::failbit | ifstream::badbit);
		try
		{
			plik.open(nazwa);
		}
		catch (ifstream::failure)
		{
			cout << "!nie mozna otworzyc pliku!" << endl;
			return;
		}
#ifdef _DEBUG  
		cout << "Wczytano dane Srodek" << endl;
#endif
		plik >> *this;
		plik.close();
	}


Srodek_transportu :: ~Srodek_transportu()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Srodek_transportu" << endl;
#endif
}