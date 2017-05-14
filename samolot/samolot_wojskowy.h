#pragma once
#include <iostream>
#include <fstream>
#include "samolot.h"

using namespace std;
///klasa Samolot_wojskowy, dziedziczy po klasie samolot
class Samolot_wojskowy : public Samolot
{
protected:
	///zmienna przechowujaca ilosc broni
	int ilosc_broni;

public:
	///konstruktor domyslny
	Samolot_wojskowy();
	///konstruktor z parametrami
	/**
	Umozliwia ustawienie ilosci miejsc, ilosci pasazerow i maksymalna wysokosc
	\param miejsca to ilosc miejsc w samolocie
	\param ilosc_osob jest liczba pasazerow
	\param max_wys jest maksymalna wysokoscia lotu
	*/
	Samolot_wojskowy(int miejsca, int ilosc_osob, float max_wys);
	///destruktor
	~Samolot_wojskowy();

	///funkcja zapisu do pliku zmiennych z klasy samolot_wojskowy
	/**
	\param nazwa to nazwa pliku txt
	*/
	virtual void zapisz_samolot_wojskowy(string nazwa);
	///funkcja odczytu z pliku zmiennych z klasy samolot_wojskowy
	/**
	\param nazwa to nazwa pliku txt
	*/
	virtual void wczytaj_samolot_wojskowy(string nazwa);
	///funkcja wypisujaca stan samolotu wojskowego
	void wypisz_stan();
	///funkcja ustawiajaca domyslne parametry samolotu wojskowego
	void ustaw_domyslne();

	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, Samolot_wojskowy& samolot_wojskowy);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Samolot_wojskowy &samolot_wojskowy);

};