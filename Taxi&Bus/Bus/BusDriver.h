#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "AbstractFactory/Driver.h"

using namespace std;

class BusDriver : public Driver
{
public:
	void info() {
		cout << "Bus Driver" << endl;
	}
};

