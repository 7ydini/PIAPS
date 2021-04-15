#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Driver.h"
#include "Passenger.h"

using namespace std;

class ChildSit : public Passenger
{
public:
	void info() {
		cout << "ChillSit" << endl;
	}
};
