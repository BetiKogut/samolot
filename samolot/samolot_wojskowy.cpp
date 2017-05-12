#include <iostream>
#include <string>
#include <fstream>
#include "samolot_wojskowy.h"

using namespace std;
using std::string;

Samolot_wojskowy::Samolot_wojskowy()
{
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor Samolot_wojskowy" << endl;
#endif
	numer = 3456;
	ilosc_miejsc = 2;
	ilosc_broni = 1200;
	
}

Samolot_wojskowy::Samolot_wojskowy(int miejsca, int ilosc_osob, float max_wys)
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor zparametrem Samolot_wojskowy" << endl;
#endif
	if (ilosc_osob <= miejsca)
	{
		numer = 123456;
		ilosc_miejsc = miejsca;
		max_wysokosc = max_wys;
		ilosc_broni = 100;

		for (int i = 0; i < ilosc_osob; i++)
		{
			Pasazerowie pasazer;
			wektor_pasazerow.push_back(pasazer);
		}
	}
	else cout << "!Za duzo osob!" << endl;


}

void Samolot_wojskowy::zapisz_samolot_wojskowy(string nazwa) 
{
	ofstream plik;
	plik.open(nazwa);
	if (!plik)
	{
		cout << "!nie mozna utworzyc pliku!";
	}
	else

	{
#ifdef _DEBUG  
		cout << "Zapisano dane Samolot_wojskowy" << endl;
#endif
		plik << *this;
		plik.close();
	}
}

void Samolot_wojskowy::wczytaj_samolot_wojskowy(string nazwa) 
{
	ifstream plik;
	plik.open(nazwa);
	if (!plik)
		cout << "!nie mozna otworzyc pliku!";
	else
	{
#ifdef _DEBUG  
		cout << "Wczytano obiekt Samolot_wojskowy" << endl;
#endif
		plik >> *this;
		plik.close();
	}

}

void Samolot_wojskowy::wypisz_stan()
{
	cout << "Uruchomiono funkcje wypisz z klasy Samolot_wojskowy" << endl;
	cout << (*this);
}


ostream& operator << (ostream& out, Samolot_wojskowy& samolot_wojskowy)
{
	out << *((Samolot*)(&samolot_wojskowy));
	out << samolot_wojskowy.ilosc_broni << endl;
	return out;
}

istream& operator >> (istream& s, Samolot_wojskowy &samolot_wojskowy)
{
	s >> *((Samolot*)(&samolot_wojskowy));
	s >> samolot_wojskowy.ilosc_broni;
	return s;
}

Samolot_wojskowy :: ~Samolot_wojskowy()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Samolot_wojskowy" << endl;
#endif
}