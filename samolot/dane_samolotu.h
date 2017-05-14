#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using namespace std;
///klasa DaneSamolotu
class DaneSamolotu {
private:
	///<zmienna przechowujaca miejsce startu lotu
	string start;
	///<zmienna przechowujaca miejsce ladowania
	string cel;

public:
	///konstruktor domyslny
	DaneSamolotu();
	///destruktor
	~DaneSamolotu();

	///metoda zwracajace start i cel lotu
	void zwrocdane();
	///metoda umozliwiajaca zmiane danych lotu
	/**
	umozliwia ustawienie nowego miejsca startu i celu lotu
	\param nowystart to miejsce nowego startu lotu
	\param nowycel to miejsce nowego celu lotu
	\return nic nie zwraca
	*/
	void zmiendane(string nowystart, string nowycel);

	///przeciazony operator =
	DaneSamolotu & operator = (const DaneSamolotu &dane);


	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, DaneSamolotu& dane);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, DaneSamolotu &dane);

};