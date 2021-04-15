#include <iostream>
#include <vector>
#include <string>

#include "Director.h"
#include "People.h"
#include "BusPeopleFactory.h"
#include "BoatPeopleFactory.h"
#include "TaxiPeopleFactory.h"
#include "PeopleFactory.h"
#include "BoardAnyCar.h"
#include "BoardBus.h"
#include "BoardTaxi.h"
#include "BoardBoat.h"



using namespace std;

int main()
{
	BoardBus busMax;
	BoardTaxi taxiMax;
	BoardBoat boatMax;

	int i = 0;
	do {
		cout << "Filling:\n1)Bus\n2)Taxi\n3)Boat\n4)Exit\n" << endl;
		cin >> i;
		switch (i)
		{

		case(1):
			busMax.loadAuto();
			break;
		case(2):
			taxiMax.loadAuto();
			break;

		case(3):
			boatMax.loadAuto();
			break;
		}
	} while (i != 4);
}