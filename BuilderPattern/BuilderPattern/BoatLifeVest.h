#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Passenger.h"

using namespace std;

class BoatLifeVest : public Passenger
{
public:
	void info() {
		cout << "BoatLifeVest" << endl;
	}
};
