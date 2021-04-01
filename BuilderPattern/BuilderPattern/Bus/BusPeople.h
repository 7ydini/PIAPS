#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Passenger.h"
#include "Driver.h"
#include "People.h"
#include "BusDriver.h"
#include "OldBusPas.h"
#include "LgotBusPas.h"
#include "ChilBusPas.h"

using namespace std;

class BusPeople : public People
{
public:
	vector<OldBusPas> vi;
	vector<LgotBusPas> va;
	vector<ChilBusPas> vh;
	vector<BusDriver> vc;
	void info() {
		int i;
		for (i = 0; i < vi.size(); ++i)  vi[i].info();
		for (i = 0; i < va.size(); ++i)  va[i].info();
		for (i = 0; i < vh.size(); ++i)  vh[i].info();
		for (i = 0; i < vc.size(); ++i)  vc[i].info();
	}
};
