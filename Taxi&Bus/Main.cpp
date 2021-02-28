#include <iostream>
#include <vector>
#include "Singleton.cpp"

using namespace std;

// Абстрактные базовые классы всех возможных видов воинов

class Driver
{
public:
	virtual void info() = 0;
	virtual ~Driver() {}
};

class BoardAnyCar
{
public:
	virtual void info() = 0;
	virtual ~BoardAnyCar() {}
};

// Классы всех видов воинов Римской армии

class BusDriver : public Driver
{
public:
	void info() {
		cout << "Driver" << endl;
	}
};

class BoardBus : public BoardAnyCar
{
public:
	void info() {
		cout << "Passenger" << endl;
	}
};
// Классы всех видов воинов армии Карфагена

class TaxiDriver : public Driver
{
public:
	void info() {
		cout << "Driver" << endl;
	}
};

class BoardTaxi : public BoardAnyCar
{
public:
	void info() {
		cout << "Passenger" << endl;
	}
};

// Абстрактная фабрика для производства воинов

class PeopleFactory
{
public:
	virtual Driver* createDriver() = 0;
	virtual BoardAnyCar* createPassenger() = 0;
	virtual ~PeopleFactory() {}
};

// Фабрика для создания воинов Римской армии

class BusPeopleFactory : public PeopleFactory
{
public:
	Driver* createDriver() {
		return new BusDriver;
	}
	BoardAnyCar* createPassenger() {
		return new BoardBus;
	}
};

// Фабрика для создания воинов армии Карфагена

class TaxiPeopleFactory : public PeopleFactory
{
public:
	Driver* createDriver() {
		return new TaxiDriver;
	}
	BoardAnyCar* createPassenger() {
		return new BoardTaxi;
	}
};

// Класс, содержащий всех воинов той или иной армии

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

// Здесь создается армия той или иной стороны

class Game
{
public:

	People* createD(PeopleFactory& factory) {
		People* p = new People;
		p->vi.push_back(factory.createDriver());
		//p->va.push_back(factory.createPassenger());
		return p;
	}
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
	int k, i = 0, j, pasTaxi = 0, pasBus = 0;
	People* bus;
	People* taxi;

	while (i != 3) {
	cout << "Filling:\n1)Bus\n2)Taxi\n3)Exit\n" << endl;
	cin >> i;
	switch (i)
	{
		
	case(1)://bus = game.createD(bus_factory);
		cout << "Fill bus\n" << endl;
		do {
			cout << "1)Add Passenger.\n2)Info\n3)Go Go Go\n" << endl;
			cin >> j;
			switch (j)
			{
			case(1):
				if (pasBus < 29) {
					pasBus++;
				}
				else cout << "Bus is full\n\n" << endl;
				break;
			case(2):
				cout << "Bus passengers: " << pasBus << " / 29" << endl;
				break;
			case(3):
				bus = game.createP(bus_factory, pasBus);
				cout << "Bus board:" << endl;
				bus->info();
				break;
			}
		} while (j != 3);
		pasBus = 0;
		break;

	case(2)://taxi = game.createD(taxi_factory);	//bus = game.createP(bus_factory);
		cout << "Fill Taxi" << endl;
		do
		{
			cout << "1)Add Passenger.\n2)Info\n3)Go Go Go\n" << endl;
			cin >> j;
			switch (j)
			{
			case(1):
				if (pasTaxi < 3) {
					pasTaxi++;
				}
				else cout << "Taxi is full\n" << endl;
				break;
			case(2):
				cout << "Taxi passengers: " << pasTaxi << " / 3" << endl;
				break;
			case(3):
				taxi = game.createP(taxi_factory, pasTaxi);
				cout << "Taxi board:" << endl;
				taxi->info();
				break;
			}
		} while (j != 3);
		pasTaxi = 0;
		break;
		}
	}
}
