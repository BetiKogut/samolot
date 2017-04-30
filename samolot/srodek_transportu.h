#pragma once
#include <iostream>
#include <fstream>

using namespace std;

///Klasa abstrakcyjna
class Srodek_transportu {
private:
	///pole przechowuj�ce typ urz�dzenia
	string typ_urzadzenia;

protected:
	int ilosc_miejsc;
	int numer;

public:
	///Kontruktor domy�lny
	Srodek_transportu();

	///Destruktor wirtualny
	virtual ~Srodek_transportu();

	///Procedura wirtualna
	//virtual void wyswietlobiekt(); = 0;

	///Operator strumieniowy <<
	friend std::ostream& operator << (std::ostream &s, Srodek_transportu &srodek_transportu);
	///Operator strumieniowy >>
	friend std::istream& operator >> (std::istream &s, Srodek_transportu &srodek_transportu);
};
