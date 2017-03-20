#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;

class Zaloga {
private:
	int pilot_id;

public:
	Zaloga(); //konstruktor
	~Zaloga(); //destruktor
	void zmienid(int noweid);
	bool operator == (const Zaloga &zaloga1);

};