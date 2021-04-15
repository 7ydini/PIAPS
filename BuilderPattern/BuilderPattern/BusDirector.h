#pragma once
#pragma once
#include"People.h"
#include"BusPeople.h"
#include"BusPeopleFactory.h"

class BusDirector
{
public:
	BusPeople* createBoard(BusPeopleFactory & builder, int OldPas, int LgotPas, int ChilPas)
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
};

