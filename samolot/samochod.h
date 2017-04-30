#pragma once
#include <iostream>
#include <fstream>
#include "srodek_transportu.h"

using namespace std;

class Samochod : public Srodek_transportu
{
protected:
	int przebieg;

public:
	Samochod();
	~Samochod();

};