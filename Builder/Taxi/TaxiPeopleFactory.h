#pragma once
#include "AbstractFactory/PeopleFactory.h"
#include "Taxi/TaxiDriver.h"
#include "Taxi/BoardTaxi.h"

class TaxiPeopleFactory : public PeopleFactory
{
public:
	void createBoard() { p = new People; }
	void buildOldPas(int i) { p->vi.push_back(OldTaxiPas()); }
	void buildChilPas(int k) { p->vh.push_back(ChilTaxiPas()); }
	void buildDriver() { p->vc.push_back(TaxiDriver()); }
};