#include <iostream>
#include <string>
#include <fstream>
#include "helikopter.h"

using namespace std;
using std::string;

Helikopter::Helikopter() 
{
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor Helikopter" << endl;
#endif
	numer = 3456;
	ilosc_miejsc = 2;
	ilosc_smigiel = 2;
	
}

Helikopter::Helikopter(int miejsca, int ilosc_osob, int max_wys)
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor zparametrem Helikopter" << endl;
#endif
	if (ilosc_osob <= miejsca)
	{
		numer = 123456;
		ilosc_miejsc = miejsca;
		max_wysokosc = max_wys;
		ilosc_smigiel = 2;

		for (int i = 0; i < ilosc_osob; i++)
		{
			Pasazerowie pasazer;
			wektor_pasazerow.push_back(pasazer);
		}
	}
	else cout << "!Za duzo osob!" << endl;


}

void Helikopter::zapisz_helikopter(string nazwa) {
#ifdef _DEBUG  
	cout << "Zapisano obiekt Helikopter" << endl;
#endif
	(*this).zapisz_samolot(nazwa);
	fstream plik;
	plik.open(nazwa);
	plik.seekg(0, ios::end);
	plik << *this;
	plik.close();
}


ostream& operator << (ostream& out, Helikopter& helikopter)
{
	out << "Ilosc smigiel: " << helikopter.ilosc_smigiel << endl;
	return out;
}

istream& operator >> (istream& s, Helikopter &helikopter)
{
	s >> helikopter.numer;
	return s;
}

Helikopter :: ~Helikopter()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Helikopter" << endl;
#endif
}