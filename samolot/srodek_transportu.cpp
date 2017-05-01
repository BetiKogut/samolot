#include <iostream>
#include <string>
#include <fstream>
#include "srodek_transportu.h"

using namespace std;

Srodek_transportu :: Srodek_transportu() {
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor Srodek_transportu" << endl;
#endif
	
}

///Zdefiniowany operator strumieniowy
std::ostream& operator << (std::ostream &s, Srodek_transportu &srodek_transportu) {
	s << srodek_transportu.numer;
	return s;
}

///Zdefiniowany operator strumieniowy
std::istream& operator >> (std::istream& s, Srodek_transportu &srodek_transportu) {
	s >> srodek_transportu.numer;
	return s;
}

Srodek_transportu :: ~Srodek_transportu()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Srodek_transportu" << endl;
#endif
}