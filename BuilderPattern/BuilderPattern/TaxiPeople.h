#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "People.h"
#include "TaxiDriver.h"
#include "OldTaxiPas.h"
//#include "LgotBusPas.h"
#include "ChilTaxiPas.h"

using namespace std;

class TaxiPeople : public People
{
public:
	vector<OldTaxiPas> vi;
	//vector<LgotBusPas> va;
	vector<ChilTaxiPas> vh;
	vector<TaxiDriver> vc;
	void info() {
		int i;
		for (i = 0; i < vi.size(); ++i)  vi[i].info();
		//for (i = 0; i < va.size(); ++i)  va[i].info();
		for (i = 0; i < vh.size(); ++i)  vh[i].info();
		for (i = 0; i < vc.size(); ++i)  vc[i].info();
	}
};
