#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Driver.h"


using namespace std;

class TaxiDriver : public Driver
{
public:
	void info() {
		cout << "Taxi Driver" << endl;
	}
};
