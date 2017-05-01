#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using namespace std;

class Pasazerowie {
private:
	string imie;
	string nazwisko;
	int klasa;
	bool nadbagaz;

public:
	Pasazerowie(); //konstruktor
	~Pasazerowie(); //destruktor
	string zwrocimie();
	string zwrocnazwisko();
	void calanazwa();
	void zmienimie(string noweimie);
	void zwrocnadbagaz();
	void operator !();

	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, Pasazerowie &pasazerowie);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Pasazerowie &pasazerowie);



};