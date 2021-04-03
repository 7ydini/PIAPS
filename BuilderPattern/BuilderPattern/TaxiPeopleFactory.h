#pragma once
#include"People.h"
#include"PeopleFactory.h"
#include"OldTaxiPas.h"
#include"ChilTaxiPas.h"
#include"TaxiDriver.h"
#include"TaxiPeople.h"

class TaxiPeopleFactory : public PeopleFactory
{
protected:
	TaxiPeople* p;
public:
	TaxiPeopleFactory() : p(0) {}
	~TaxiPeopleFactory() {}
	void createBoard() { p = new TaxiPeople(); }
	void buildOldPas() { p->vi.push_back(OldTaxiPas()); }
	//void buildLgotPas() { p->va.push_back(LgotBusPas()); }
	void buildChilPas() { p->vh.push_back(ChilTaxiPas()); }
	void buildDriver() { p->vc.push_back(TaxiDriver()); }
	TaxiPeople* getPeople() { return p; }
};