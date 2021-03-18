#pragma once
#include "Driver.h"
#include "BoardAnyCar.h"

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
	virtual void buildDriver() {}
	//virtual void buildElephant() {}
	virtual People* getPeople() { return p; }
};