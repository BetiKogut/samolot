#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;

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


};