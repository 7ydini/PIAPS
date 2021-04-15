#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Passenger.h"
#include "Driver.h"
#include "People.h"
#include "TaxiDriver.h"
#include "OldTaxiPas.h"
//#include "LgotBusPas.h"
#include "ChilTaxiPas.h"
#include "ChildSit.h"

using namespace std;

class TaxiPeople : public People
{
public:
	vector<OldTaxiPas> vi;
	vector<ChilTaxiPas> vh;
	vector<TaxiDriver> vc;
	vector<ChildSit> vd;
	void info() {
		int i;
		for (i = 0; i < vc.size(); ++i)  vc[i].info();
		for (i = 0; i < vi.size(); ++i)  vi[i].info();
		for (i = 0; i < vd.size(); ++i)  vd[i].info();
		for (i = 0; i < vh.size(); ++i)  vh[i].info();
	}
};
