#pragma once
#include <iostream>
#include <fstream>
#include "samolot.h"

using namespace std;

class Samolot_wojskowy : public Samolot
{
protected:
	int ilosc_broni;

public:
	Samolot_wojskowy();
	Samolot_wojskowy(int miejsca, int ilosc_osob, float max_wys);
	~Samolot_wojskowy();

	virtual void zapisz_samolot_wojskowy(string nazwa);
	virtual void wczytaj_samolot_wojskowy(string nazwa);

	void wypisz_stan();

	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, Samolot_wojskowy& samolot_wojskowy);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Samolot_wojskowy &samolot_wojskowy);

};