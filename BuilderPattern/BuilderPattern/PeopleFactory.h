#pragma once
#include "People.h"

class PeopleFactory
{
protected:
	People* p;
public:
	PeopleFactory() : p(0) {}
	virtual ~PeopleFactory() {}
	virtual void createBoard() {}
	virtual void buildOldPas() {}
	virtual void buildLgotPas() {}
	virtual void buildChilPas() {}
	virtual void buildLifeVest() {}
	virtual void buildDriver() {}
	//virtual void buildPassenger() {}

	virtual People* getPeople() { return p; }
};

