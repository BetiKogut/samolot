#include <iostream>
#include <string>
#include "samolot.h"

using namespace std;

using std::string;

void testuj()
{
	Samolot samolot1, samolot2;
	Pasazerowie *pasazer1;
	pasazer1 = new Pasazerowie();
	Zaloga zaloga1, zaloga2;
	DaneSamolotu dane1, dane2;
	Samolot samolot3(samolot2);

	cout << endl << "Testowanie operatorow:" << endl;

	cout << "Operator + napisow:" << endl;
	cout << "Imie: " << pasazer1->zwrocimie();
	cout << endl << "Nazwisko: " << pasazer1->zwrocnazwisko();
	cout << endl << "Cala nazwa: ";
	pasazer1->calanazwa();

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
	pasazer1->zwrocnadbagaz();
	!*(pasazer1);
	cout << endl << "Nadbagaz=";
	pasazer1->zwrocnadbagaz();

	cout << endl << endl << "Operator << :" << endl;
	cout << samolot1;
	
	Samolot::statycznametoda();

	cout << endl << endl;


	delete  pasazer1;
	
}

int main() 
{
	int a,przycisk=0;
	string imie, nazwisko;

#ifdef _DEBUG
	
	testuj();

#endif


	cin >> a;
}