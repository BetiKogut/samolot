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
	numer = 0;
	ilosc_miejsc = 0;
	max_wysokosc = 0;

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

void zmienilosc(Samolot & samolot, int nowailosc)
{
	samolot.ilosc_miejsc = nowailosc;
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

void Samolot::zapisz_samolot(string nazwa) {
#ifdef _DEBUG  
	cout << "Zapisano dane Samolot" << endl;
#endif
	ofstream plik;
	plik.open(nazwa);
	plik << *this;
	plik.close();

}

void Samolot::wczytaj_samolot(string nazwa) {
#ifdef _DEBUG  
	cout << "Wczytano obiekt Samolot" << endl;
#endif
	/*string smietnik;
	(*this).wczytaj_srodek(nazwa);
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

void Samolot::wypisz_stan()
{	
	cout << "Uruchomiono funkcje wypisz z klasy samolot" << endl;
	cout << (*this).numer << endl << (*this).ilosc_miejsc << endl << (*this).max_wysokosc << endl;
}


//destruktor
Samolot::~Samolot()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Samolot" << endl;
#endif
	liczba_obiektow--;

}