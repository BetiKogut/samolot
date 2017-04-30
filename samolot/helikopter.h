#pragma once
#include <iostream>
#include <fstream>
#include "samolot.h"

using namespace std;

class Helikopter : public Samolot
{
protected:
	int ilosc_smigiel;

public:
	Helikopter();
	~Helikopter();

};