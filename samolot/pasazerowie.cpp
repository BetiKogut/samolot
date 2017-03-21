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
	imie = "Adam";
	nazwisko = "Abacki";
	nadbagaz = 1;
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

void Pasazerowie::operator!()
{
	if (nadbagaz == 1)
		nadbagaz = 0;
	else nadbagaz = 1;
}



//destruktor
Pasazerowie::~Pasazerowie()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Pasazerowie" << endl;
#endif
}