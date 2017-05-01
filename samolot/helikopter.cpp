#include <iostream>
#include <string>
#include <fstream>
#include "helikopter.h"

using namespace std;

Helikopter :: Helikopter() {
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor Helikopter" << endl;
#endif
	ilosc_smigiel = 2;
}

Helikopter :: ~Helikopter()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Helikopter" << endl;
#endif
}

ostream& operator << (ostream& out, Helikopter& helikopter)
{
	out << helikopter.numer << endl;
	return out;
}

istream& operator >> (istream& s, Helikopter &helikopter)
{
	s >> helikopter.numer;
	return s;
}