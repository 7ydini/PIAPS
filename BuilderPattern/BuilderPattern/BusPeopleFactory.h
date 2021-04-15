#pragma once
#include"BusPeople.h"
#include"PeopleFactory.h"
#include"OldBusPas.h"
#include"lgotBusPas.h"
#include"ChilBusPas.h"
#include"BusDriver.h"

class BusPeopleFactory : public PeopleFactory
{
protected:
	BusPeople* p;
public:
	BusPeopleFactory() : p(0) {}
	~BusPeopleFactory() {}
	void createBoard() { p = new BusPeople; }
	void buildOldPas() { p->vi.push_back(OldBusPas()); }
	void buildLgotPas() { p->va.push_back(LgotBusPas()); }
	void buildChilPas() { p->vh.push_back(ChilBusPas()); }
	void buildDriver() { p->vc.push_back(BusDriver()); }
	BusPeople* getPeople() { return p; }
};


