#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using namespace std;

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


	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, DaneSamolotu& dane);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, DaneSamolotu &dane);

};