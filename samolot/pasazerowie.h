#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using namespace std;
///klasa Pasazerowie
class Pasazerowie {
private:
	string imie;///<zmienna przechowujaca imie pasazera
	string nazwisko;	///<zmienna przechowujaca nazwisko pasazera
	bool nadbagaz;///<zmienna logiczna przechowujaca informacje czy pasazer posiada nadbagaz

public:
	///konstruktor domyslny
	Pasazerowie();
	///destruktor
	~Pasazerowie();

	///metoda zwracajaca imie 
	/**
	\return zwraca imie pasazera
	*/
	string zwrocimie();
	///metoda zwracajaca nazwisko
	/**
	\return zwraca nazwisko pasazera
	*/
	string zwrocnazwisko();
	///metoda wypisujaca ³¹cznie imie i nazwisko
	void calanazwa();
	///metoda pozwalajaca na zmiane imienia
	/**
	\param noweimie to nowe imie pasazera
	\return nic nie zwraca
	*/
	void zmienimie(string noweimie);
	///metoda pozwalajaca na zmiane nazwiska
	/**
	\param nowenazwisko to nowe nazwisko pasazera
	\return nic nie zwraca
	*/
	void zmiennazwisko(string nowenazwisko);
	///metoda zwracajaca informacje czy pasazer posiada nadbagaz
	void zwrocnadbagaz();
	///przeciazony operator !
	void operator !();

	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, Pasazerowie &pasazerowie);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Pasazerowie &pasazerowie);



};