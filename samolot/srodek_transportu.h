#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "pasazerowie.h"

using namespace std;

///Klasa abstrakcyjna Srodek_transportu
class Srodek_transportu {

protected:
	///<zmienna przechowujaca ilosc miejsc w srodku transportu
	int ilosc_miejsc;
	///<zmienna przechowujaca numer srodku transportu
	int numer;
	///wektor przechowujacy pasazerow samolotu
	vector <Pasazerowie> wektor_pasazerow;

public:
	///Kontruktor domyœlny
	Srodek_transportu();

	///Destruktor wirtualny
	virtual ~Srodek_transportu();

	///funkcja zapisu do pliku zmiennych z klasy srodek_transportu
	/**
	\param nazwa to nazwa pliku txt
	*/
	void zapisz_srodek(string nazwa);
	///funkcja odczytu z pliku zmiennych z klasy srodek_transportu
	/**
	\param nazwa to nazwa pliku txt
	*/
	void wczytaj_srodek(string nazwa);
	///metoda wirtualna wypisywania stanu
	virtual void wypisz_stan()=0;
	///metoda wirtualna ustawiajaca domyslne dane
	virtual void ustaw_domyslne()=0;

	///Operator strumieniowy <<
	friend std::ostream& operator << (std::ostream &s, Srodek_transportu &srodek_transportu);
	///Operator strumieniowy >>
	friend std::istream& operator >> (std::istream &s, Srodek_transportu &srodek_transportu);
};
