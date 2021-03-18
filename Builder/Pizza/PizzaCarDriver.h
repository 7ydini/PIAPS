#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "AbstractFactory/Driver.h"

using namespace std;

class PizzaCarDriver : public Driver
{
public:
	void info() {
		cout << "PizzaCar Driver" << endl;
	}
};
