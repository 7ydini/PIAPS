#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Passenger.h"
#include "Driver.h"
#include "People.h"
#include "BoatDriver.h"
#include "BoatOldPas.h"
#include "BoatLifeVest.h"
#include "BoatChildPas.h"

using namespace std;

class BoatPeople : public People
{
public:
	vector<BoatOldPas> vi;
	vector<BoatLifeVest> va;
	vector<BoatChildPas> vh;
	vector<BoatDriver> vc;
	void info() {
		int i;
		for (i = 0; i < vc.size(); ++i)  vc[i].info();
		for (i = 0; i < va.size(); ++i)  va[i].info();
		for (i = 0; i < vi.size(); ++i)  vi[i].info();
		for (i = 0; i < vh.size(); ++i)  vh[i].info();		
	}
};
