#pragma once
#include "AbstractFactory/PeopleFactory.h"
#include "Taxi/TaxiDriver.h"
#include "Taxi/BoardTaxi.h"

class TaxiPeopleFactory : public PeopleFactory
{
public:
	Driver* createDriver() {
		return new TaxiDriver;
	}
	BoardAnyCar* createPassenger() {
		return new BoardTaxi;
	}
};