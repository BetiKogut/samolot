#include <iostream>
#include <string>
#include <fstream>
#include "samochod.h"

using namespace std;

Samochod::Samochod() {
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor Samochod" << endl;
#endif
	przebieg = 100000;
}

Samochod :: ~Samochod()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Samochod" << endl;
#endif
}

ostream& operator << (ostream& out, Samochod& samochod)
{
	out << samochod.numer << endl;
	return out;
}

istream& operator >> (istream& s, Samochod &samochod)
{
	s >> samochod.numer;
	return s;
}