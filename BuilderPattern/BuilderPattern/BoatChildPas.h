#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Passenger.h"

using namespace std;

class BoatChildPas : public Passenger
{
public:
	void info() {
		cout << "BoatChildPas" << endl;
	}
};
