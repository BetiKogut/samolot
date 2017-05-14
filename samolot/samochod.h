#pragma once
#include <iostream>
#include <fstream>
#include "srodek_transportu.h"

using namespace std;
///klasa samochod, dziedziczy po klasie srodek_transportu
class Samochod : public Srodek_transportu
{
protected:
	///zmienna przechowujaca przebieg samochodu
	int przebieg;

public:
	///konstruktor domyslny
	Samochod();
	///destruktor
	~Samochod();

	///funkcja zapisu do pliku zmiennych z klasy samochod
	/**
	\param nazwa to nazwa pliku txt
	*/
	void zapisz_samochod(string nazwa);
	///funkcja odczytu z pliku zmiennych z klasy samochod
	/**
	\param nazwa to nazwa pliku txt
	*/
	void wczytaj_samochod(string nazwa);
	///funkcja wypisujaca stan samochodu
	virtual void wypisz_stan();
	///funkcja ustawiajaca parametry domyslne samochodu
	virtual void ustaw_domyslne();

	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, Samochod& samochod);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Samochod &samochod);

};