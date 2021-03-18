#pragma once
#include "Driver.h"
#include "BoardAnyCar.h"

class PeopleFactory
{
public:
	virtual Driver* createDriver() = 0;
	virtual BoardAnyCar* createPassenger() = 0;
	virtual ~PeopleFactory() {}
};