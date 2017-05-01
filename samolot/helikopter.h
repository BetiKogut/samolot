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
	~Helikopter();

	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, Helikopter& helikopter);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Helikopter &helikopter);

};