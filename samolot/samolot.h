#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "zaloga.h"
#include "dane_samolotu.h"
#include "srodek_transportu.h"
#include <vector>

using std::string;
using namespace std;

///Klasa Samolot, dziedziczy po klasie Srodek_transportu
class Samolot : public Srodek_transportu {
protected:
	///Podklasa klasy samolot
	Zaloga zaloga;
	///Podklasa klasy samolot
	DaneSamolotu daneSamolotu;
	///zmienna przechowujaca liczbe stworzonych obiektow samolot
	static int liczba_obiektow;
	///zmienna przechowujaca maksymalna wysokosc lotu
	float max_wysokosc;

public:
	///konstruktor domyslny
	Samolot();
	///konstruktor z parametrami
	/**
	Umozliwia ustawienie liczby miejsc w samolocie i liczby pasazerow
	\param miejsca to ilosc miejsc w samolocie
	\param ilosc_osob to liczba pasazerow
	*/
	Samolot(int miejsca, int ilosc_osob);
	///konstruktor kopiujacy
	Samolot(Samolot &samolot);
	///destruktor
	~Samolot();
	///metoda zwracajaca ilosc miejsc w samolocie
	void zwroc_iloscmiejsc();
	///metoda z parametrem zmieniajaca ilosc miejsc w smolocie
	/**
	\param nowailosc to nowa ilosc miejsc
	*/
	void zmienilosc(int nowailosc);
	///metoda statyczna wyswietlajaca ilosc stworzonych obiektow samolot
	static void statycznametoda();

	///funkcja zapisu do pliku zmiennych z klasy samolot
	/**
	\param nazwa to nazwa pliku txt
	*/
	void zapisz_samolot(string nazwa);
	///funkcja odczytu z pliku zmiennych z klasy samolot
	/**
	\param nazwa to nazwa pliku txt
	*/
	void wczytaj_samolot(string nazwa);
	///funkcja wypisujaca stan samolotu
	virtual void wypisz_stan();
	///funkcja wirtualna ustawiajaca parametry domyslne samolotu
	virtual void ustaw_domyslne();

	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, Samolot& samolot);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Samolot &samolot);

	///przeciazony operator >
	bool operator > (const Samolot &samolot);
	///przeciazony operator <
	bool operator < (const Samolot &samolot);
	///przeciazony operator +
	int operator + (const Samolot &samolot);
	///przeciazony operator ()
	operator int() const;
	///przeciazony operator ++
	Samolot& operator ++ (int);
	///przeciazony operator --
	Samolot& operator -- (int);
	///przeciazony operator []
	Pasazerowie& operator [](int pozycja);
	///przeciazony operator =
	Samolot& operator = (const Samolot &samolot);

};
