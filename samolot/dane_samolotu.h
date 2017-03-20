#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;

class DaneSamolotu {
private:
	string start;
	string cel;

public:
	DaneSamolotu(); //konstruktor
	~DaneSamolotu(); //destruktor
	void zwrocdane();
	void zmiendane(string nowystart, string nowycel);

	DaneSamolotu & operator = (const DaneSamolotu &dane);

};