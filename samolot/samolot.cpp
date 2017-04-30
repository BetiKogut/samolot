#include <iostream>
#include <string>
#include <fstream>
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
	numer = 123456;
	ilosc_miejsc = 150;
	pasazerowie = NULL;
	pasazerowie = new Pasazerowie[4];
}

Samolot::Samolot(Samolot& samolot)
{
	cout << "Wywolano kostruktor kopiujacy samolot" << endl;
	liczba_obiektow++;
	numer = samolot.numer;
	ilosc_miejsc = samolot.ilosc_miejsc;
	pasazerowie = new Pasazerowie[4];
	for (int i = 0; i < 4; i++)
	{
		pasazerowie[i] = samolot.pasazerowie[i];
	}

	daneSamolotu = samolot.daneSamolotu;
	zaloga = samolot.zaloga;



}
Samolot& Samolot :: operator = (const Samolot &samolot)
{
	if (this != &samolot)
	{
		delete[]pasazerowie;
		numer = samolot.numer;
		ilosc_miejsc = samolot.ilosc_miejsc;
		pasazerowie = new Pasazerowie[4];
		for (int i = 0; i < 4; i++)
		{
			pasazerowie[i] = samolot.pasazerowie[i];
		}

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

ostream& operator << (ostream& out, const Samolot& samolot)
{
	cout << samolot.ilosc_miejsc << endl;
	return out;
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

	return pasazerowie[pozycja];
}

Samolot::operator int() const
{
	return ilosc_miejsc;
}

//destruktor
Samolot::~Samolot()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Samolot" << endl;
#endif
	liczba_obiektow--;
	delete[]pasazerowie;
}