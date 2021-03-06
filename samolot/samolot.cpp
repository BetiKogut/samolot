#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "samolot.h"

using namespace std;
int Samolot::liczba_obiektow = 0;

//konstruktor

Samolot::Samolot()
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor Samolot" << endl;
#endif
	liczba_obiektow++;
	numer = 11111;
	ilosc_miejsc = 100;
	max_wysokosc = 10;

}

Samolot::Samolot(int miejsca, int ilosc_osob)
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor zparametrem Samolot" << endl;
#endif
	liczba_obiektow++;
	if (ilosc_osob <= miejsca)
	{
		numer = 123456;
		ilosc_miejsc=miejsca;
		max_wysokosc = 10;

		for (int i = 0; i < ilosc_osob; i++)
		{
			Pasazerowie pasazer;
			wektor_pasazerow.push_back(pasazer);
		}
	}
	else cout << "!Za duzo osob!" << endl;

	
}

Samolot::Samolot(Samolot& samolot)
{
	cout << "Wywolano kostruktor kopiujacy samolot" << endl;
	liczba_obiektow++;
	numer = samolot.numer;
	ilosc_miejsc = samolot.ilosc_miejsc;
	wektor_pasazerow = samolot.wektor_pasazerow;
	daneSamolotu = samolot.daneSamolotu;
	zaloga = samolot.zaloga;



}
Samolot& Samolot :: operator = (const Samolot &samolot)
{
	if (this != &samolot)
	{
		numer = samolot.numer;
		ilosc_miejsc = samolot.ilosc_miejsc;
		wektor_pasazerow = samolot.wektor_pasazerow;
		daneSamolotu = samolot.daneSamolotu;
		zaloga = samolot.zaloga;

		return *this;
	}
	else
		cout << "Nie mozna uzyc operatora = do tych samych danych!";

}



void Samolot::statycznametoda()
{
	cout << endl << "Liczba stworzonych obiektow: " << liczba_obiektow << endl;
}

ostream& operator << (ostream& out, Samolot& samolot)
{
	out << *((Srodek_transportu*)(&samolot));
	out << samolot.max_wysokosc << endl;
	return out;
}

istream& operator >> (istream& s, Samolot &samolot) 
{
	s >> *((Srodek_transportu*)(&samolot));
	s >> samolot.max_wysokosc;
	return s;
}

void Samolot::zwroc_iloscmiejsc()
{
	cout << ilosc_miejsc;
}

void Samolot::zmienilosc(int nowailosc)
{
	ilosc_miejsc = nowailosc;
}

bool Samolot :: operator> (const Samolot &samolot)
{
	if (samolot.ilosc_miejsc > ilosc_miejsc)
		return true;
	else return false;
}

bool Samolot :: operator< (const Samolot &samolot)
{
	if (samolot.ilosc_miejsc < ilosc_miejsc)
		return true;
	else return false;
}

int Samolot :: operator + (const Samolot &samolot)
{
	return (samolot.ilosc_miejsc + ilosc_miejsc);

}

Samolot & Samolot :: operator++(int)
{
	ilosc_miejsc++;
	return *this;
}

Samolot & Samolot :: operator--(int)
{
	if (ilosc_miejsc != 0)
	{
		ilosc_miejsc--;
		return *this;
	}
	else
	{
		cout << endl << "!Nie mozna bardziej zmnejszyc ilosci miejsc!";
		return *this;
	}

}

Pasazerowie& Samolot::operator[](int pozycja)
{

	return wektor_pasazerow[pozycja];
}

Samolot::operator int() const
{
	return ilosc_miejsc;
}

void Samolot::zapisz_samolot(string nazwa) 
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
	cout << "Zapisano dane Samolot" << endl;
#endif
	plik << *this;
	plik.close();
}

void Samolot::wczytaj_samolot(string nazwa) 
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
		cout << "Wczytano dane Samolot_wojskowy" << endl;
#endif
		plik >> *this;
		plik.close();
}

void Samolot::wypisz_stan()
{	
	cout << endl << "Uruchomiono funkcje wypisz z klasy samolot" << endl;
	cout << (*this);
}

void Samolot::ustaw_domyslne()
{
	cout << endl << "Uruchomiono funkcje ustaw_domyslne z klasy samolot" << endl;
	numer = 11111;
	ilosc_miejsc = 100;
	max_wysokosc = 10;
	for (int i = 0; i < wektor_pasazerow.size(); i++)
	{
		wektor_pasazerow[i].zmienimie("Domyslne_imie");
		wektor_pasazerow[i].zmiennazwisko("Domyslne_nazwisko");
	}
}


Samolot::~Samolot()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Samolot" << endl;
#endif
	liczba_obiektow--;

}