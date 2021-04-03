#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Passenger.h"


using namespace std;

class LgotBusPas : public Passenger
{
public:
	void info() {
		cout << "LgotBusPas" << endl;
	}
};

