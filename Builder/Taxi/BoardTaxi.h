#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "AbstractFactory/BoardAnyCar.h"
#include "AbstractFactory/OldPas.h"
#include "AbstractFactory/ChilPas.h"


using namespace std;


class BoardTaxi : public BoardAnyCar
{
public:
	int OldPas = 0, ChilPas = 0;
	int pasMax = 3;
	void info() {
		cout << "Taxi Passenger" << endl;
	}
	
	void LoadTaxi(BoardTaxi b) {
		//loadAuto("Passenger", "Bus", busMax.pasMax);
		int pass = 0;
		//cout << "Bus went, board:" << endl;
		//bus->info();
		do {
			cout << "1)Add Passenger.\n2)Info.\n3)Go Go Go.\n" << endl;
			cin >> j;
			switch (j)
			{
			case(1): {

				if (pass < passMax) {
					cout << "1)Add Grown \n" << "2)Add Beneficiary \n" << "3)Add Child" << endl;
					int t = 0;

					while (t < 1 && t > 2)
					{
						cin >> t;
					}
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
				else cout << "Bus is full\n" << endl;
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
				People* bus;
				bus = dir.createBoard(bus_factory, b.OldPas, b.LgotPas, b.ChilPas);
				cout << "Taxi went, board:" << endl;
				b->info();
				break;
			}
			}

			}
		} while (j != 3);
};


class OldTaxiPas : public Passenger
{
public:
	void info() {
		cout << "OldTaxiPas" << endl;
	}
};


class ChilTaxiPas : public Passenger
{
public:
	void info() {
		cout << "ChillTaxiPas" << endl;
	}
};