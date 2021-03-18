#pragma once
#include "AbstractFactory/PeopleFactory.h"
#include "Bus/BusDriver.h"
#include "Bus/BoardBus.h"
#include "Bus/OldBusPas.h"
#include "Bus/LgotBusPas.h"
#include "Bus/ChilBusPas.h"

class BusPeopleFactory : public PeopleFactory
{
public:
	void createBoard() { p = new People; }
	void buildOldPas() { p->vi.push_back(OldPas()); }
	void buildLgotPas() { p->va.push_back(LgotPas()); }
	void buildChilPas() { p->vh.push_back(ChilPas()); }
	void buildDriver() { p->vc.push_back(BusDriver()); }
};
