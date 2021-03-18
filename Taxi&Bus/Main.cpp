#include <iostream>
#include <vector>
#include <string>

#include "AbstractFactory/BoardAnyCar.h"
#include "AbstractFactory/Driver.h"
#include "AbstractFactory/peopleFactory.h"

#include "Pizza/PizzaCarDriver.h"
#include "Pizza/BoardPizzaCar.h"
#include "Pizza/PizzaFactory.h"

#include "Taxi/BoardTaxi.h"
#include "Taxi/TaxiDriver.h"
#include "Taxi/TaxiPeopleFactory.h"

#include "Bus/BoardBus.h"
#include "Bus/BusDriver.h"
#include "Bus/BusPeopleFactory.h"

//#include "Singleton.cpp"

using namespace std;

// Абстрактные базовые классы для пассажира и водителя
int loadAuto(string pasType, string name, int passMax);

class People
{
public:
	~People() {
		int i;
		for (i = 0; i < vi.size(); ++i) delete vi[i];
		for (i = 0; i < va.size(); ++i) delete va[i];
	}
	void info() {
		int i;
		for (i = 0; i < vi.size(); ++i) vi[i]->info();
		for (i = 0; i < va.size(); ++i) va[i]->info();

	}
	vector<Driver*> vi;
	vector<BoardAnyCar*> va;

};

class Game
{
public:
	People* createP(PeopleFactory& factory, int pas) {
		People* p = new People;
		p->vi.push_back(factory.createDriver());
		for (int i = 0; i < pas; i++)
		{
			p->va.push_back(factory.createPassenger());
		}
		return p;
	}
};

int main()
{
	Game game;

	BusPeopleFactory bus_factory;
	TaxiPeopleFactory taxi_factory;
	PizzaFactory pizza_factory;
	BoardBus busMax;
	BoardTaxi taxiMax;
	BoardPizzaCar pizzaMax;
	int i = 0;
	People* bus;
	People* taxi;
	People* pizza;
	do {
		cout << "Filling:\n1)Bus\n2)Taxi\n3)PizzaCar\n4)Exit\n" << endl;
		cin >> i;
		switch (i)
		{

		case(1):
			bus = game.createP(bus_factory, loadAuto("Passenger", "Bus", busMax.pasMax));
			cout << "Bus went, board:" << endl;
			bus->info();
			break;
		case(2):
			taxi = game.createP(taxi_factory, loadAuto("Passenger", "Taxi", taxiMax.pasMax));
			cout << "Taxi went, board:" << endl;
			taxi->info();
			break;

		case(3):
			pizza = game.createP(pizza_factory, loadAuto("Pizza", "PizzaCar", pizzaMax.pasMax));
			cout << "PizzaCar went, board:" << endl;
			pizza->info();
			break;
		}
	} while (i != 4);
}

int loadAuto(string pasType, string name, int passMax) {
	cout << "Fill " << name << endl;
	int pass = 0, j = 0;
	do
	{
		cout << "1)Add " << pasType << ".\n2)Info\n3)Go Go Go\n" << endl;
		cin >> j;
		switch (j)
		{
		case(1):
			if (pass < passMax) {
				pass++;
				cout << pasType << " added: " << pass << " / " << passMax << ".\n" << endl;
			}
			else cout << name << " is full\n" << endl;
			break;
		case(2):

			cout << name << " " << pasType << "s: " << pass << " / " << passMax << ".\n" << endl;
			break;
		case(3):
			return pass;
			break;
		}
	} while (j != 3);
}