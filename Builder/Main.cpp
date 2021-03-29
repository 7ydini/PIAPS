#include <iostream>
#include <vector>
#include <string>

#include "AbstractFactory/BoardAnyCar.h"
#include "AbstractFactory/Driver.h"
#include "AbstractFactory/PeopleFactory.h"
//#include "AbstractFactory/OldPas.h"
//#include "AbstractFactory/LgotPas.h"
//#include "AbstractFactory/ChilPas.h"
#include "AbstractFactory/Passenger.h"


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

// Àáñòðàêòíûå áàçîâûå êëàññû äëÿ ïàññàæèðà è âîäèòåëÿ
//BoardBus loadAuto(string pasType, string name, int passMax);
class Director
{
public:
	People* createBoard(PeopleFactory & builder, int OldPas, int LgotPas, int ChilPas)
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
		//builder.buildElephant();
		builder.getPeople();
	}
};

//class Army
//{
//public:
//	vector<Passenger> vop;
//	vector<Passenger> vlp;
//	vector<Passenger> vcp;
//	vector<Driver> vd;
//	//vector<Catapult> vc;
//	//vector<Elephant> ve;
//	void info() {
//		int i;
//		for (i = 0; i < vop.size(); ++i)  vop[i].info();
//		for (i = 0; i < vlp.size(); ++i)  vlp[i].info();
//		for (i = 0; i < vcp.size(); ++i)  vcp[i].info();
//		for (i = 0; i < vd.size(); ++i)  vd[i].info();
//		//for (i = 0; i < ve.size(); ++i)  ve[i].info();
//	}
//};
//
//class ArmyBuilder
//{
//protected:
//	Army* p;
//public:
//	ArmyBuilder() : p(0) {}
//	virtual ~ArmyBuilder() {}
//	virtual void createArmy() {}
//	virtual void buildInfantryman() {}
//	virtual void buildArcher() {}
//	virtual void buildHorseman() {}
//	virtual void buildCatapult() {}
//	virtual void buildElephant() {}
//	virtual Army* getArmy() { return p; }
//};


class People
{
public:
	vector<Passenger> vi;
	vector<Passenger> va;
	vector<Passenger> vh;
	vector<Driver> vc;
	//vector<Elephant>    ve;
	void info() {
		int i;
		for (i = 0; i < vi.size(); ++i)  vi[i].info();
		for (i = 0; i < va.size(); ++i)  va[i].info();
		for (i = 0; i < vh.size(); ++i)  vh[i].info();
		for (i = 0; i < vc.size(); ++i)  vc[i].info();
		//for (i = 0; i < ve.size(); ++i)  ve[i].info();
	}
};

int main()
{
	//Game game;
	Director dir;

	People* bus;
	People* taxi;
	BusPeopleFactory bus_factory;
	TaxiPeopleFactory taxi_factory;
	PizzaFactory pizza_factory;
	BoardBus busMax;
	BoardTaxi taxiMax;
	BoardPizzaCar pizzaMax;
	int i = 0;
	do {
		cout << "Filling:\n1)Bus\n2)Taxi\n3)PizzaCar\n4)Exit\n" << endl;
		cin >> i;
		switch (i)
		{

		case(1):
			//loadAuto("Passenger", "Bus", busMax.pasMax);
			//bus = dir.createBoard(bus_factory, busMax.OldPas, busMax.LgotPas, busMax.ChilPas);
			busMax.LoadBus(busMax);
			//bus = dir.createBoard(bus_factory, busMax.OldPas, busMax.LgotPas, busMax.ChilPas);
			break;
			//cout << "Bus went, board:" << endl;
			
			break;
		case(2):
			taxiMax.LoadTaxi(taxiMax);
			//loadAuto("Passenger", "Taxi", taxiMax.pasMax);
			//taxi = dir.createBoard(taxi_factory, taxiMax.OldPas, 0, taxiMax.ChilPas);
			//cout << "Taxi went, board:" << endl;
			//taxi->info();
			break;

		case(3):
			//pizza = dir.createBoard(pizza_factory, loadAuto("Pizza", "PizzaCar", pizzaMax.pasMax));
			cout << "PizzaCar went, board:" << endl;
			//pizza->info();
			break;
		}
	} while (i != 4);
}
