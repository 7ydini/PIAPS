#include <iostream>
#include <vector>
#include <string>

#include "AbstractFactory/BoardAnyCar.h"
#include "AbstractFactory/Driver.h"
#include "AbstractFactory/PeopleFactory.h"
#include "AbstractFactory/OldPas.h"
#include "AbstractFactory/LgotPas.h"
#include "AbstractFactory/ChilPas.h"
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
		return(builder.getPeople());
	}
};

class Army
{
public:
	vector<OldPas> vop;
	vector<LgotPas> vlp;
	vector<ChilPas> vcp;
	vector<Driver> vd;
	//vector<Catapult> vc;
	//vector<Elephant> ve;
	void info() {
		int i;
		for (i = 0; i < vop.size(); ++i)  vop[i].info();
		for (i = 0; i < vlp.size(); ++i)  vlp[i].info();
		for (i = 0; i < vcp.size(); ++i)  vcp[i].info();
		for (i = 0; i < vd.size(); ++i)  vd[i].info();
		//for (i = 0; i < ve.size(); ++i)  ve[i].info();
	}
};

class ArmyBuilder
{
protected:
	Army* p;
public:
	ArmyBuilder() : p(0) {}
	virtual ~ArmyBuilder() {}
	virtual void createArmy() {}
	virtual void buildInfantryman() {}
	virtual void buildArcher() {}
	virtual void buildHorseman() {}
	virtual void buildCatapult() {}
	virtual void buildElephant() {}
	virtual Army* getArmy() { return p; }
};


class People
{
public:
	vector<OldPas> vi;
	vector<LgotPas> va;
	vector<ChilPas> vh;
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

//class Game
//{
//public:
//	People* createP(PeopleFactory& factory, int OldPas) {
//		People* p = new People;
//		p->vc.push_back(factory.buildDriver());
//		for (int i = 0; i < OldPas; i++)
//		{
//			p->vi.push_back(factory.buildOldPas());
//		}
//		return p;
//	}
//};

int main()
{
	//Game game;
	Director dir;

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
			break;
			//cout << "Bus went, board:" << endl;
			
			break;
		case(2):
			taxiMax.loadTaxi(TaxiMax);
			//loadAuto("Passenger", "Taxi", taxiMax.pasMax);
			//taxi = dir.createBoard(taxi_factory, taxiMax.OldPas, 0, taxiMax.ChilPas);
			//cout << "Taxi went, board:" << endl;
			//taxi->info();
			break;

		case(3):
			//pizza = dir.createBoard(pizza_factory, loadAuto("Pizza", "PizzaCar", pizzaMax.pasMax));
			cout << "PizzaCar went, board:" << endl;
			pizza->info();
			break;
		}
	} while (i != 4);
}

//BoardBus loadAuto(string pasType, string name, int passMax) {
//	cout << "Fill " << name << endl;
//	BoardBus b;
//	int pass = 0, j = 0;
//	do
//	{
//		cout << "1)Add " << pasType << ".\n2)Info\n3)Go Go Go\n" << endl;
//		cin >> j;
//		switch (j)
//		{
//		case(1): {
//			
//			if (pass < passMax) {
//				cout << "1)Add Grown \n" << "2)Add Beneficiary \n" << "3)Add Child" << endl;
//				int t = 0;
//				
//				while (t < 1 && t > 3)
//				{
//					cin >> t;
//				}
//				switch (t) {
//				case(1):
//					b.OldPas++;
//
//				case(2):
//					b.LgotPas++;
//			
//				case(3):
//					b.ChilPas++;
//				}
//				pass++;
//				cout << pasType << " added: " << pass << " / " << passMax << ".\n" << endl;
//			}
//			else cout << name << " is full\n" << endl;
//			break;
//		}
//		case(2):
//
//			cout << name << " " << pasType << "s: " << pass << " / " << passMax << ".\n" << endl;
//			break;
//		case(3):
//			return b;
//			break;
//		}
//	} while (j != 3);
//}
