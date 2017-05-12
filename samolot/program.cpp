#include <iostream>
#include <string>
#include "srodek_transportu.h"
#include "samolot.h"
#include "helikopter.h"
#include "samochod.h"
#include <vector>

using namespace std;

using std::string;

void testuj()
{	
	vector <Srodek_transportu*> obiekt;
	Samolot samolot1(100, 3), samolot2(50, 5);
	obiekt.push_back(&samolot1);
	obiekt.push_back(&samolot2);
	Pasazerowie pasazer1;
	Zaloga zaloga1, zaloga2;
	DaneSamolotu dane1, dane2;
	Samolot samolot3(samolot2);
	obiekt.push_back(&samolot3);

	cout << endl << "Testowanie operatorow:" << endl;

	cout << "Operator + napisow:" << endl;
	cout << "Imie: " << pasazer1.zwrocimie();
	cout << endl << "Nazwisko: " << pasazer1.zwrocnazwisko();
	cout << endl << "Cala nazwa: ";
	pasazer1.calanazwa();

	cout << endl << endl << "Operator == :" << endl;
	if (zaloga1 == zaloga2)
		cout << "true" << endl;
	else cout << "false" << endl;
	zaloga2.zmienid(234);
	if (zaloga1 == zaloga2)
		cout << "true";
	else cout << "false";

	cout << endl << endl << "Operator > :" << endl;
	if (samolot1 > samolot2)
		cout << "true" << endl;
	else cout << "false" << endl;
	zmienilosc(samolot2, 200);
	if (samolot1 > samolot2)
		cout << "true";
	else cout << "false";

	cout << endl << endl << "Operator < :" << endl;
	if (samolot1 < samolot2)
		cout << "true" << endl;
	else cout << "false" << endl;

	cout << endl << endl << "Operator ++ :" << endl << "Przed: ";
	samolot2.zwroc_iloscmiejsc();
	cout << endl << "Po: ";
	samolot2++;
	samolot2.zwroc_iloscmiejsc();

	cout << endl << endl << "Operator -- :" << endl;
	samolot2--;
	samolot2.zwroc_iloscmiejsc();
	samolot2.zmienilosc(0);
	samolot2--;

	cout << endl << endl << "Operator = :" << endl;
	dane2.zmiendane("Londyn", "NY");
	cout << "Poczatkowe dane: " << endl;
	dane1.zwrocdane();
	dane2.zwrocdane();
	dane1 = dane2;
	cout << endl << "Dane po zastosowaniu operatora: " << endl;
	dane1.zwrocdane();
	dane2.zwrocdane();
	cout << endl;
	dane1 = dane1;

	cout << endl << endl << "Operator = dla Samolot:" << endl << "dane samolotu 1: ";
	samolot1.zwroc_iloscmiejsc();
	cout << endl;
	cout << samolot1[2].zwrocimie();
	cout << endl << "dane samolotu 2: ";
	samolot2.zwroc_iloscmiejsc();
	cout << endl;
	cout << samolot2[2].zwrocimie();
	samolot1 = samolot2;
	cout << endl << "Po przypisaniu: " << endl << "dane samolotu 1: ";
	samolot1.zwroc_iloscmiejsc();
	cout << endl;
	cout << samolot1[2].zwrocimie();
	cout << endl << "dane samolotu 2: ";
	samolot2.zwroc_iloscmiejsc();
	cout << endl;
	cout << samolot2[2].zwrocimie();

	cout << endl << endl << "Operator [] :" << endl;
	cout << samolot1[2].zwrocimie();
	samolot1[2].zmienimie("Marek");
	cout << endl << samolot1[2].zwrocimie();

	cout << endl << endl << "Operator konwersji int() :" << endl;
	int ilosc = (int)samolot1;
	cout << ilosc;

	cout << endl << endl << "Operator + :";
	int suma = samolot1 + samolot2;
	cout << endl << suma;

	cout << endl << endl << "Operator ! :";
	cout << endl << "Nadbagaz=";
	pasazer1.zwrocnadbagaz();
	!(pasazer1);
	cout << endl << "Nadbagaz=";
	pasazer1.zwrocnadbagaz();

	cout << endl << endl << "Operator << :" << endl;
	cout << samolot1;
	cin >> samolot1;
	cout << samolot1;
	
	Samolot::statycznametoda();

	cout << endl << endl;

}

int main()
{
	int przycisk = 0;
	int opcja=0;
	string imie, nazwisko;
	Samolot sam1(20,15);
	Helikopter heli1(15,5,12);
	Samochod samochod1;
	Srodek_transportu *srodek_transportu[3];
	srodek_transportu[0] = &sam1;
	srodek_transportu[1] = &samochod1;
	srodek_transportu[2] = &heli1;
	system("cls");

#ifdef _DEBUG

	do 
	{
		cout << endl << endl << "~~~~Menu programu~~~~" << endl << endl;
		cout << "[0] Zamknij program" << endl;
		cout << "[1] Testy podstawowe klas" << endl;
		cout << "[2] Testy zapisu do pliku" << endl;
		cout << "[3] Testy polimorfizmu na konstruktorach i destruktorach"<< endl;
		cout << "[4] Test funkcji wirtualnej " << endl;
		cin >> opcja;

		switch (opcja)
		{

		case 0:
			break;
		case 1:
			testuj();
			break;

		case 2:
			sam1.zapisz_samolot("samolot.txt");
			heli1.zapisz_helikopter("helikopter.txt");
			samochod1.zapisz_samochod("samochod.txt");
			cout << "Stan samochodu: " << endl;
			sam1.wypisz_stan();
			sam1.wczytaj_samolot("samolot_test.txt");
			cout << endl << "Nowy stan samolotu:" << endl;
			sam1.wypisz_stan();
			cout << endl << "Stan helikoptera:" << endl;
			heli1.wypisz_stan();
			heli1.wczytaj_helikopter("helikopter_test.txt");
			cout << endl << "Nowy stan helikoptera:" << endl;
			heli1.wypisz_stan();

			break;

		case 3:
			Srodek_transportu *srodek;

			srodek = new Helikopter(15,3,13);
			delete srodek;
			break;

		case 4:
			for (int i = 0; i < 3; i++)
			{
				srodek_transportu[i]->wypisz_stan();
			}
			break;

		default:
			cout << "!bledne dane!" << endl;
			break;
			 
		}
	} while (opcja != 0);

#endif

}