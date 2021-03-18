#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "AbstractFactory/BoardAnyCar.h"
#include "AbstractFactory/OldPas.h"
#include "AbstractFactory/LgotPas.h"
#include "AbstractFactory/ChilPas.h"


using namespace std;

class BoardBus : public BoardAnyCar
{
public:
	int OldPas = 0, LgotPas = 0, ChilPas = 0;
	int pasMax = 29;
	void info() {
		cout << "Bus Passenger" << endl;
	}
};


class OldBusPas : public OldPas
{
public:
	void info() {
		cout << "OldBusPas" << endl;
	}
};

class LgotBusPas : public LgotPas
{
public:
	void info() {
		cout << "LgotBusPas" << endl;
	}
};

class ChilBusPas : public ChilPas
{
public:
	void info() {
		cout << "ChillBusPas" << endl;
	}
};