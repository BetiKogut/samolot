#pragma once
#include <iostream>
#include <fstream>
#include "samolot.h"

using namespace std;

class Helikopter : public Samolot
{
protected:
	int ilosc_smigiel;

public:
	Helikopter();
	Helikopter(int miejsca, int ilosc_osob, int max_wys);
	~Helikopter();

	virtual void zapisz_helikopter(string nazwa);

	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, Helikopter& helikopter);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Helikopter &helikopter);

};