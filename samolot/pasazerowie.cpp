#include <iostream>
#include <string>
#include <fstream>
#include "pasazerowie.h"

using namespace std;

//konstruktor
Pasazerowie::Pasazerowie()
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor Pasazerowie" << endl;

#endif
	imie = "Domyslne_imie";
	nazwisko = "Domyslne_nazwisko";
	nadbagaz = 0;
}

string Pasazerowie::zwrocimie()
{
	return imie;
}

string Pasazerowie::zwrocnazwisko()
{
	return nazwisko;
}

void Pasazerowie::calanazwa()
{
	string calanazwa;
	calanazwa = imie + " " + nazwisko;
	cout << calanazwa;
}

void Pasazerowie::zwrocnadbagaz()
{
	cout << nadbagaz;
}

void Pasazerowie::zmienimie(string noweimie)
{
	imie = noweimie;
}

void Pasazerowie::zmiennazwisko(string nowenazwisko)
{
	nazwisko = nowenazwisko;
}

void Pasazerowie::operator!()
{
	if (nadbagaz == 1)
		nadbagaz = 0;
	else nadbagaz = 1;
}

ostream& operator << (ostream& out, Pasazerowie &pasazerowie)
{
	out << pasazerowie.imie << " " << pasazerowie.nazwisko << endl;
	return out;
}

istream& operator >> (istream& s, Pasazerowie &pasazerowie)
{
	s >> pasazerowie.imie >> pasazerowie.nazwisko;
	return s;
}


Pasazerowie::~Pasazerowie()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Pasazerowie" << endl;
#endif
}