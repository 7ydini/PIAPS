#pragma once
#include "People.h"
#include "PeopleFactory.h"
#include"OldTaxiPas.h"
#include"ChilTaxiPas.h"
#include"TaxiDriver.h"
#include"TaxiPeople.h"
#include"ChildSit.h"


class TaxiPeopleFactory : public PeopleFactory
{
protected:
	TaxiPeople* p;
public:
	TaxiPeopleFactory() : p(0) {}
	~TaxiPeopleFactory() {}
	void createBoard() { p = new TaxiPeople; }
	void buildDriver() { p->vc.push_back(TaxiDriver()); }
	void buildOldPas() { p->vi.push_back(OldTaxiPas()); }
	void buildChildSet() { p->vd.push_back(ChildSit()); }
	void buildChilPas() { p->vh.push_back(ChilTaxiPas()); }
	
	TaxiPeople* getPeople() { return p; }
};