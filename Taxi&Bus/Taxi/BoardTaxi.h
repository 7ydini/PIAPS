#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "AbstractFactory/BoardAnyCar.h"

using namespace std;


class BoardTaxi : public BoardAnyCar
{
public:
	int pasMax = 3;
	void info() {
		cout << "Passenger" << endl;
	}
};
