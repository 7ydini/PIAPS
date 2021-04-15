#pragma once
#include"People.h"
#include"PeopleFactory.h"
#include"BoatPeopleFactory.h"
#include"TaxiPeopleFactory.h"
#include"TaxiPeople.h"
#include"BusPeopleFactory.h"
#include"BusPeople.h"
#include"BoatPeople.h"

class Director
{
public:
	People* createBoard(PeopleFactory& builder, int OldPas, int LgotPas, int ChilPas)
	{
		builder.createBoard();
		for (int z = 0; z < OldPas; z++) {
			builder.buildOldPas();
		}
		for (int z = 0; z < LgotPas; z++) {
			builder.buildLgotPas();
		}
		for (int z = 0; z < ChilPas; z++) {
			builder.buildChilPas();
		}
		builder.buildDriver();

		return{ builder.getPeople() };
	}

	BusPeople* createBusBoard(BusPeopleFactory& builder, int OldPas, int LgotPas, int ChilPas) {

		builder.createBoard();
		for (int z = 0; z < OldPas; z++) {
			builder.buildOldPas();
		}
		for (int z = 0; z < LgotPas; z++) {
			builder.buildLgotPas();
		}
		for (int z = 0; z < ChilPas; z++) {
			builder.buildChilPas();
		}
		builder.buildDriver();

		return{ builder.getPeople() };
	}

	TaxiPeople* createTaxiBoard(TaxiPeopleFactory& builder, int OldPas, int ChilPas)
	{
		builder.createBoard();
		builder.buildDriver();
		for (int z = 0; z < OldPas; z++) {
			builder.buildOldPas();
		}
		for (int z = 0; z < ChilPas; z++) {
			builder.buildChildSet();
			builder.buildChilPas();
		}
		return{ builder.getPeople() };
	}
	BoatPeople* createBoatBoard(BoatPeopleFactory& builder, int OldPas, int ChilPas)
	{
		builder.createBoard();
		for (int z = 0; z < OldPas; z++) {
			builder.buildOldPas();
			builder.buildLifeVest();
		}
		for (int z = 0; z < ChilPas; z++) {
			builder.buildChilPas();
			builder.buildLifeVest();
		}
		builder.buildDriver();

		return{ builder.getPeople() };
	}
};

