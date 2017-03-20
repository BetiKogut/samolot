#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "pasazerowie.h"
#include "zaloga.h"
#include "dane_samolotu.h"

using std::string;
using namespace std;

class Samolot {
private:
	int numer;
	int ilosc_miejsc;
	Pasazerowie *pasazerowie;
	Zaloga zaloga;
	DaneSamolotu daneSamolotu;
	static int liczba_obiektow;

public:

	Samolot(); //konstruktor
	Samolot(Samolot &samolot);//konstruktor kopiujacy
	~Samolot(); //destruktor
	friend void zmienilosc(Samolot &, int nowailosc);
	void zwroc_iloscmiejsc();
	void zmienilosc(int nowailosc);
	static void statycznametoda();

	friend ostream& operator << (ostream& out, const Samolot& samolot);

	bool operator > (const Samolot &samolot);
	bool operator < (const Samolot &samolot);
	int operator + (const Samolot &samolot);
	operator int() const;
	Samolot & operator ++ (int);
	Samolot & operator -- (int);
	Pasazerowie& operator [](int pozycja);

};
