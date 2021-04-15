#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "BoardAnyCar.h"
#include "BoatPeopleFactory.h"
#include "People.h"
#include "BoatPeople.h"
#include "Director.h"


using namespace std;

class BoardBoat : public BoardAnyCar
{
public:
	int OldPas = 0, ChilPas = 0;
	int pasMax = 15;
	void info() {
		cout << "Boat Passenger" << endl;
	}
	void loadAuto() {
		int pass = 0, j = 0;
		BoardBoat b = BoardBoat();
		do {
			cout << "1)Add Passenger.\n2)Info.\n3)Go Go Go.\n" << endl;
			cin >> j;
			switch (j)
			{
			case(1): {

				if (pass < pasMax) {
					cout << "1)Add Grown \n" << "2)Add Child" << endl;
					int t;
					do {
						cin >> t;
					} while (t < 1 && t > 3);
					switch (t) {
					case(1):
						b.OldPas++;
						pass++;
						cout << "Grown added: " << pass << " / " << b.pasMax << ".\n" << endl;
						break;
					case(2):
						b.ChilPas++;
						pass++;
						cout << "Child added! Passengers: " << pass << " / " << b.pasMax << ".\n" << endl;
						break;
					}
					//pass++;

				}
				else cout << "Boat is full\n" << endl;
			}
			case(2): {
				cout << "Boat Passengers: " << pass << " / " << b.pasMax << ".\n" << endl;
				cout << "Boat Child passengers: " << b.ChilPas << ".\n" << endl;
				cout << "Boat Grown passengers: " << b.OldPas << ".\n" << endl;
				cout << "Life Vest: " << pass << endl;
				break;
			}
			case(3):
			{
				BoatPeopleFactory boat_factory;
				Director dir;
				BoatPeople* boat;
				boat = dir.createBoatBoard(boat_factory, b.OldPas, b.ChilPas);
				cout << "Boat went, board:" << endl;
				boat->info();
				break;
			}

			}
		} while (j != 3);

	}
};