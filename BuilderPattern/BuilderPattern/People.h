#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Passenger.h"
#include "Driver.h"

using namespace std;

class People
{
public:
	vector<Passenger> vi;
	vector<Passenger> va;
	vector<Passenger> vh;
	vector<Driver> vc;
	void info() {
		int i;
		for (i = 0; i < vi.size(); ++i)  vi[i].info();
		for (i = 0; i < va.size(); ++i)  va[i].info();
		for (i = 0; i < vh.size(); ++i)  vh[i].info();
		for (i = 0; i < vc.size(); ++i)  vc[i].info();
	}	
};

