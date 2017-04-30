#include <iostream>
#include <string>
#include <fstream>
#include "srodek_transportu.h"

using namespace std;

Srodek_transportu :: Srodek_transportu() {
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor Srodek_transportu" << endl;
#endif
	typ_urzadzenia = "domyslny_typ";
}

///Zdefiniowany operator strumieniowy
std::ostream& operator << (std::ostream &s, Srodek_transportu &srodek_transportu) {
	s << srodek_transportu.typ_urzadzenia;
	return s;
}

///Zdefiniowany operator strumieniowy
std::istream& operator >> (std::istream& s, Srodek_transportu &srodek_transportu) {
	s >> srodek_transportu.typ_urzadzenia;
	return s;
}

Srodek_transportu :: ~Srodek_transportu()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Srodek_transportu" << endl;
#endif
}