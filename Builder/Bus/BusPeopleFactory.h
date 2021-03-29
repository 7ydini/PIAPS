#pragma once
#include "../AbstractFactory/PeopleFactory.h"
#include "BusDriver.h"
#include "BoardBus.h"
#include "../Main.cpp"
//#include "Bus/OldBusPas.h"
//#include "Bus/LgotBusPas.h"
//#include "Bus/ChilBusPas.h"

class BusPeopleFactory : public PeopleFactory
{
	
public:
	void createBoard() { p = new People; }
	void buildOldPas() { p->vi.push_back(OldBusPas()); }
	void buildLgotPas() { p->va.push_back(LgotBusPas()); }
	void buildChilPas() { p->vh.push_back(ChilBusPas()); }
	void buildDriver() { p->vc.push_back(BusDriver()); }
};
