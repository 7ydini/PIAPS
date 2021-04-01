#pragma once
#include"People.h"
#include"PeopleFactory.h"

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

	BusPeople* createBusBoard(BusPeopleFactory& builder, int OldPas, int LgotPas, int ChilPas){

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
		for (int z = 0; z < OldPas; z++) {
			builder.buildOldPas();
		}
		for (int z = 0; z < ChilPas; z++) {
			builder.buildChilPas();
		}
		builder.buildDriver();

		return{ builder.getPeople() };
	}
};

