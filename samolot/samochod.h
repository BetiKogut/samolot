#pragma once
#include <iostream>
#include <fstream>
#include "srodek_transportu.h"

using namespace std;
///Klasa Samochod, dziedziczy po klasie Srodek_transportu
class Samochod : public Srodek_transportu
{
protected:
	
	int przebieg;///< zmienna przechowujaca przebieg 

public:
	///konstruktor domyslny
	Samochod();
	///konstruktor z parametrem
	Samochod(int miejsca, int ilosc_osob);
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