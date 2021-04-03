#include <iostream>
#include <vector>
#include <string>

#include "BoardAnyCar.h"
#include "BusPeopleFactory.h"
#include "People.h"
#include "BusPeople.h"
#include "Director.h"


using namespace std;

class BoardBus : public BoardAnyCar
{
public:
	int OldPas = 0, LgotPas = 0, ChilPas = 0;
	int pasMax = 29;
	void info() {
		cout << "Bus Passenger" << endl;
	}
	void loadAuto() {
		int pass = 0, j = 0;
		BoardBus b = BoardBus();
		do {
			cout << "1)Add Passenger.\n2)Info.\n3)Go Go Go.\n" << endl;
			cin >> j;
			switch (j)
			{
			case(1): {

				if (pass < pasMax) {
					cout << "1)Add Grown \n" << "2)Add Beneficiary \n" << "3)Add Child" << endl;
					int t;
					do{
						cin >> t;
					} while (t < 1 && t > 3);
					switch (t) {
					case(1):
						b.OldPas++;
						pass++;
						cout << "Grown added: " << pass << " / " << b.pasMax << ".\n" << endl;
						break;
					case(2):
						b.LgotPas++;
						pass++;
						cout << "Beneficiary added: " << pass << " / " << b.pasMax << ".\n" << endl;
						break;
					case(3):
						b.ChilPas++;
						pass++;
						cout << "Child added! Passebgers: " << pass << " / " << b.pasMax << ".\n" << endl;
						break;
					}
					//pass++;

				}
				else cout << "Bus is full\n" << endl;
			}
			case(2): {
				cout << "Bus Passengers: " << pass << " / " << b.pasMax << ".\n" << endl;
				cout << "Bus Child passengers: " << b.ChilPas << ".\n" << endl;
				cout << "Bus Beneficiary passengers: " << b.LgotPas << ".\n" << endl;
				cout << "Bus Grown passengers: " << b.OldPas << ".\n" << endl;
				break;
			}
			case(3):
			{
				BusPeopleFactory bus_factory;
				Director dir;
				BusPeople* bus;
				bus = dir.createBusBoard(bus_factory, b.OldPas, b.LgotPas, b.ChilPas);
				cout << "Bus went, board:" << endl;
				bus->info();
				break;
			}

			}
		} while (j != 3);

	}
};