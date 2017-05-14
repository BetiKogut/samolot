#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using namespace std;
///Klasa Zaloga
class Zaloga {
private:
	///mienna przechowujaca numer id pilota
	int pilot_id;

public:
	///konstruktor domyslny
	Zaloga();
	///destruktor
	~Zaloga();
	///metoda umozliwiajaca zmiane id
	/**
	\param nowe id pilota
	\return nic nie zwraca
	*/
	void zmienid(int noweid);
	///przeciazony operator ==
	bool operator == (const Zaloga &zaloga1);

	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, Zaloga& zaloga);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Zaloga &zaloga);

};