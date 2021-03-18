#pragma once
#include "AbstractFactory/PeopleFactory.h"
#include "Pizza/PizzaCarDriver.h"
#include "Pizza/BoardPizzaCar.h"

class PizzaFactory : public PeopleFactory
{
public:
	Driver* createDriver() {
		return new PizzaCarDriver;
	}
	BoardAnyCar* createPassenger() {
		return new BoardPizzaCar;
	}
};