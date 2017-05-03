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
	Samolot(10, 15);
	Samolot samolot1(100, 3), samolot2(50, 5);
	Pasazerowie pasazer1;
	Zaloga zaloga1, zaloga2;
	DaneSamolotu dane1, dane2;
	Samolot samolot3(samolot2);

	cout << endl << "Testowanie operatorow:" << endl;

	cout << "Operator + napisow:" << endl;
	cout << "Imie: " << pasazer1.zwrocimie();//
	cout << endl << "Nazwisko: " << pasazer1.zwrocnazwisko();//
	cout << endl << "Cala nazwa: ";
	pasazer1.calanazwa();//

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
	pasazer1.zwrocnadbagaz();//
	!(pasazer1);
	cout << endl << "Nadbagaz=";
	pasazer1.zwrocnadbagaz();//

	cout << endl << endl << "Operator << :" << endl;
	cout << samolot1;
	cin >> samolot1;
	cout << samolot1;
	
	Samolot::statycznametoda();

	cout << endl << endl;


	//delete  pasazer1;

}

int main()
{
	int a, przycisk = 0;
	int opcja=0;
	string imie, nazwisko;
	Samolot sam1(20,15);
	Helikopter heli1(15,5,12);
	Samochod samochod1;
	system("cls");

#ifdef _DEBUG

	do 
	{
		cout << endl << endl << "~~~~Menu programu~~~~" << endl << endl;
		cout << "[0]zamknij program" << endl;
		cout << "[1]Testy podstawowe klas" << endl;
		cout << "[2]" "Testy zapisu do pliku" << endl;
		cout << "[3]" "Testy polimorfizmu na konstruktorach i destruktorach"<< endl;
		cout << "[4]" << endl;
		cin >> opcja;

		switch (opcja)
		{

		case 0:
			break;
		case 1:
			testuj();
			break;

		case 2:
			cout << "wybrano 2" << endl;
			sam1.zapisz_samolot("samolot.txt");
			heli1.zapisz_helikopter("helikopter.txt");
			samochod1.zapisz_samochod("samochod.txt");
			break;

		case 3:
			Srodek_transportu *srodek;

			srodek = new Helikopter();
			delete srodek;
			break;

		case 4:
			cout << "wybrano 4";
			break;

		default:
			cout << "!bledne dane!" << endl;
			break;
			 
		}
	} while (opcja != 0);
	//testuj();

#endif


	//cin >> a;
}