#include <iostream>
#include <string>
#include <fstream>
#include "samochod.h"

using namespace std;

Samochod::Samochod() {
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor Samochod" << endl;
#endif
	numer = 11111;
	ilosc_miejsc = 5;
	przebieg = 10000;
}

Samochod::Samochod(int miejsca, int ilosc_osob)
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor zparametrem Samolot" << endl;
#endif
	if (ilosc_osob <= miejsca)
	{
		numer = 11111;
		ilosc_miejsc = miejsca;
		przebieg = 10000;

		for (int i = 0; i < ilosc_osob; i++)
		{
			Pasazerowie pasazer;
			wektor_pasazerow.push_back(pasazer);
		}
	}
	else cout << "!Za duzo osob!" << endl;


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

void Samochod::zapisz_samochod(string nazwa) 
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
	cout << "Zapisano dane Samochod" << endl;
#endif
	plik << *this;
	plik.close();
}

void Samochod::wczytaj_samochod(string nazwa) 
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
	cout << "Wczytano dane Samochod" << endl;
#endif
	plik >> *this;
	plik.close();
}


void Samochod :: wypisz_stan()
{
	cout << endl << "Uruchomiono funkcje wypisz z klasy samochod:" << endl;
	cout << (*this);
}

void Samochod::ustaw_domyslne()
{
	cout << endl << "Uruchomiono funkcje ustaw_domyslne z klasy samochod" << endl;
	numer = 11111;
	ilosc_miejsc = 5;
	przebieg = 100000;
	for (int i = 0; i < wektor_pasazerow.size(); i++)
	{
		wektor_pasazerow[i].zmienimie("Domyslne_imie");
		wektor_pasazerow[i].zmiennazwisko("Domyslne_nazwisko");
	}
}

Samochod :: ~Samochod()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Samochod" << endl;
#endif
}