#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "AbstractFactory/BoardAnyCar.h"

using namespace std;

class BoardBus : public BoardAnyCar
{
public:
	int pasMax = 29;
	void info() {
		cout << "Passenger" << endl;
	}
};
