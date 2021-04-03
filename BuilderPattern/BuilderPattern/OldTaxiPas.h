#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Driver.h"
#include "Passenger.h"

using namespace std;

class OldTaxiPas : public Passenger
{
public:
	void info() {
		cout << "OldTaxiPas" << endl;
	}
};
