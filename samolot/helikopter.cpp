#include <iostream>
#include <string>
#include <fstream>
#include "helikopter.h"

using namespace std;

Helikopter :: Helikopter() {
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor Helikopter" << endl;
#endif
	ilosc_smigiel = 2;
}

Helikopter :: ~Helikopter()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Helikopter" << endl;
#endif
}