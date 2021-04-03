#pragma once
#include <iostream>
#include <vector>
#include <string>
#include"Passenger.h"

using namespace std;

class OldBusPas : public Passenger
{
public:
	void info() {
		cout << "OldBusPas" << endl;
	}
};
