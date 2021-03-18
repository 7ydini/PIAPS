#pragma once
#include "AbstractFactory/PeopleFactory.h"
#include "Bus/BusDriver.h"
#include "Bus/BoardBus.h"

class BusPeopleFactory : public PeopleFactory
{
public:
	Driver* createDriver() {
		return new BusDriver;
	}
	BoardAnyCar* createPassenger() {
		return new BoardBus;
	}
};
