#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Passenger.h"

using namespace std;

class ChilBusPas : public Passenger
{
public:
	void info() {
		cout << "ChillBusPas" << endl;
	}
};
