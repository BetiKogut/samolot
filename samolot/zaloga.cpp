#include <iostream>
#include <string>
#include <fstream>
#include "zaloga.h"

using namespace std;

//konstruktor
Zaloga::Zaloga()
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor Zaloga" << endl;
	pilot_id = 123;
#endif
}

bool Zaloga :: operator == (const Zaloga &zaloga1)
{
	if (zaloga1.pilot_id == pilot_id)
		return true;
	else return false;
}

void Zaloga::zmienid(int noweid)
{
	pilot_id = noweid;
}

//destruktor
Zaloga::~Zaloga()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Zaloga" << endl;
#endif
}