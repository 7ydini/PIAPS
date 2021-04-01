#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Driver.h"
#include "Passenger.h"

using namespace std;

class ChilTaxiPas : public Passenger
{
public:
	void info() {
		cout << "ChillTaxiPas" << endl;
	}
};
