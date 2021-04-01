#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "BoardAnyCar.h"
#include "TaxiPeopleFactory.h"
#include "People.h"
#include "TaxiPeople.h"
#include "Director.h"


using namespace std;

class BoardTaxi : public BoardAnyCar
{
public:
	int OldPas = 0, ChilPas = 0;
	int pasMax = 3;
	void info() {
		cout << "Taxi Passenger" << endl;
	}

	void loadAuto() {
		//loadAuto("Passenger", "Bus", busMax.pasMax);
		int pass = 0, j = 0;
		BoardTaxi b = BoardTaxi();
		//cout << "Bus went, board:" << endl;
		//bus->info();
		do {
			cout << "1)Add Passenger.\n2)Info.\n3)Go Go Go.\n" << endl;
			cin >> j;
			switch (j)
			{
			case(1): {

				if (pass < pasMax) {
					cout << "1)Add Grown \n" << "2)Add Beneficiary \n" << "3)Add Child" << endl;
					int t = 0;
					do {
						cin >> t;
					} while (t < 1 && t > 2);

					switch (t) {
					case(1):
					{
						b.OldPas++;
						pass++;
						cout << "Grown added: " << pass << " / " << b.pasMax << ".\n" << endl;
						break;
					}
					case(2):
					{
						b.ChilPas++;
						pass++;
						cout << "Child added! Passebgers: " << pass << " / " << b.pasMax << ".\n" << endl;
						break;
					}
					}
					//pass++;

				}
				else cout << "Taxi is full\n" << endl;
			}
			case(2): {

				cout << "Taxi Passengers: " << pass << " / " << b.pasMax << ".\n" << endl;
				cout << "Taxi Child passengers: " << b.ChilPas << ".\n" << endl;
				cout << "Taxi Grown passengers: " << b.OldPas << ".\n" << endl;
				break;
			}

			case(3):
			{
				TaxiPeopleFactory taxi_factory;
				Director dir;
				TaxiPeople* taxi;
				taxi = dir.createTaxiBoard(taxi_factory, b.OldPas, b.ChilPas);
				cout << "Taxi went, board:" << endl;
				taxi->info();
				break;
			}
			}
		} while (j != 3);
	};
};

