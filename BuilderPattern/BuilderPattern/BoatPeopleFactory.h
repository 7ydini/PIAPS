#pragma once
#include"BoatPeople.h"
#include"PeopleFactory.h"
#include"BoatOldPas.h"
#include"BoatChildPas.h"
#include"BoatDriver.h"

class BoatPeopleFactory : public PeopleFactory
{
protected:
	BoatPeople* p;
public:
	BoatPeopleFactory() : p(0) {}
	~BoatPeopleFactory() {}
	void createBoard() { p = new BoatPeople; }
	void buildOldPas() { p->vi.push_back(BoatOldPas()); }
	void buildLifeVest() { p->va.push_back(BoatLifeVest()); }
	void buildChilPas() { p->vh.push_back(BoatChildPas()); }
	void buildDriver() { p->vc.push_back(BoatDriver()); }
	BoatPeople* getPeople() { return p; }
};
