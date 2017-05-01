#include <iostream>
#include <string>
#include <fstream>
#include "zaloga.h"

using namespace std;

//konstruktor
Zaloga::Zaloga()
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor Zaloga" << endl;
#endif
	pilot_id = 123;
}

bool Zaloga :: operator == (const Zaloga &zaloga1)
{
	if (zaloga1.pilot_id == pilot_id)
		return true;
	else return false;
}

void Zaloga::zmienid(int noweid)
{
	pilot_id = noweid;
}

ostream& operator << (ostream& out, Zaloga& zaloga)
{
	out << zaloga.pilot_id << endl;
	return out;
}

istream& operator >> (istream& s, Zaloga &zaloga)
{
	cout << "Wpisz numer id pilota: ";
	s >> zaloga.pilot_id;
	return s;
}

//destruktor
Zaloga::~Zaloga()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Zaloga" << endl;
#endif
}