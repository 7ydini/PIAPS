#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Driver.h"

using namespace std;

class BoatDriver : public Driver
{
public:
	void info() {
		cout << "BoatDriver" << endl;
	}
};
