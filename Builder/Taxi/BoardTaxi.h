#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "AbstractFactory/BoardAnyCar.h"
#include "AbstractFactory/OldPas.h"
#include "AbstractFactory/ChilPas.h"


using namespace std;


class BoardTaxi : public BoardAnyCar
{
public:
	int OldPas = 0, ChilPas = 0;
	int pasMax = 3;
	void info() {
		cout << "Taxi Passenger" << endl;
	}
};


class OldTaxiPas : public OldPas
{
public:
	void info() {
		cout << "OldTaxiPas" << endl;
	}
};


class ChilTaxiPas : public ChilPas
{
public:
	void info() {
		cout << "ChillTaxiPas" << endl;
	}
};