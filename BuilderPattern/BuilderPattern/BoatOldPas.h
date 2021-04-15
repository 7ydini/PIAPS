#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Passenger.h"

using namespace std;

class BoatOldPas : public Passenger
{
public:
	void info() {
		cout << "BoatOldPas" << endl;
	}
};
