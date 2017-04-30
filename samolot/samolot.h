#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "pasazerowie.h"
#include "zaloga.h"
#include "dane_samolotu.h"
#include "srodek_transportu.h"

using std::string;
using namespace std;

///Klasa Samolot, dziedziczy po klasie Srodek_transportu
class Samolot : public Srodek_transportu {
private:
	Pasazerowie *pasazerowie;
	Zaloga zaloga;
	DaneSamolotu daneSamolotu;
	static int liczba_obiektow;

protected:
	float max_wysokosc;

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
	Samolot & operator = (const Samolot &samolot);

};
