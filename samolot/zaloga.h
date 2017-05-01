#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using namespace std;

class Zaloga {
private:
	int pilot_id;

public:
	Zaloga(); //konstruktor
	~Zaloga(); //destruktor
	void zmienid(int noweid);
	bool operator == (const Zaloga &zaloga1);

	///Operator strumieniowy <<
	friend ostream& operator << (ostream& out, Zaloga& zaloga);

	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Zaloga &zaloga);

};