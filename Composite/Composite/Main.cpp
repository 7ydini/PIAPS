#include <iostream>
#include <vector>
#include <assert.h>

// Component

class People
{
public:
	int place;
	int bag;
	virtual void getInfo() {}

	virtual void passAdded() {
	}
	virtual void deleteUnit(int index) {}
	virtual int getBaggage(int index) { return 0;}
	virtual void delBaggage(int index) {}
	virtual void passDelete() {
		
	}
	virtual void addUnit(People* p) {

		assert(false);
	}
	virtual ~People() {}
};

// Primitives

class Pylot : public People
{
public:
	virtual void getInfo() {
		std::cout << "Pylot" << std::endl;
	}
};

class Stuard : public People
{
public:
	virtual void getInfo() {
		std::cout << "Stuard" << std::endl;
	}
};

class FirstClassPassenger : public People
{
public:
	FirstClassPassenger(int bag, int place) {
		this->bag = bag;
		this->place = place;
		passAdded();
	}
	void getInfo() {
		std::cout << "Place(" << place << ") " << "FirstClassPassenger baggage: " << bag << std::endl;
	}
};

class BusinessClassPassenger : public People
{
public:
	BusinessClassPassenger(int bag, int place) {
		this->bag = bag;
		this->place = place;
		passAdded();
	}
	void getInfo() {
		std::cout << "Place(" << place << ") " << "BusinessClassPassenger baggage: " << bag << std::endl;
	}
};

class EcoClassPassenger : public People
{
public:
	EcoClassPassenger(int bag, int place) {
		this->bag = bag;
		this->place = place;
		passAdded();
	}
	void getInfo() {
		std::cout << "Place(" << place << ") " << "EconomyClassPassenger baggage: " << bag << std::endl;
	}
};

class Baggage : public People
{
public:
	int bag = 0;
	Baggage(int b) {
		bag = b;
	}
	virtual void getInfo() {
		std::cout << "Снят с рейса багаж пассажира эконом класса(кг): " << bag << std::endl;
	}
};

// Composite

class CompositePeople : public People
{
public:

	void getInfo() {
		for (int i = 0; i < c.size(); i++)
			c[i]->getInfo();
	}
	void addUnit(People* p) {

		c.push_back(p);

	}
	void deleteUnit(int index) {

		c.erase((c.begin()+index), (c.begin() + index+1));
	}
	int getBaggage(int index) {
		return c[index]->bag;
	}


	~CompositePeople() {

		for (int i = 0; i < c.size(); i++)
			delete c[i];

	}

private:

	std::vector<People*> c;

};

// Вспомогательная функция для создания борта

CompositePeople* createBoard()

{
	// Борт содержит:
	CompositePeople* board = new CompositePeople;

	// 2 Пилота
	for (int i = 0; i < 2; i++)
		board->addUnit(new Pylot);

	//6 Стюардов
	for (int i = 0; i < 6; i++)
		board->addUnit(new Stuard);

	//До 10 пассажиров первого, бизнес (макс. 20 чел) и эконом (150 чел) classov.
	
	return board;

}

int main()
{
	int cs = 0, pass = 1, sumBag = 0, maxBag = 2000, bn = 0, count = 0;
	int passMaxF = 10, placeF = 0, passMaxB = 20, placeB = 10, passMaxE = 150, placeE = 30;
	int* baggage = new int[150];
	int airplanePlaces[180];
	setlocale(LC_ALL, "Russian");
	CompositePeople* board = new CompositePeople;
	board->addUnit(createBoard());
	while (cs != 4) {
		cs = 0;
		do {
			std::cout << "(1)Добавить пассажира\n(2)Удалить пассажира.\n(3)Информация\n(4)Отправиться.\nВвод >> ";
			std::cin >> cs;
		} while (cs < 0 || cs > 5);
		switch (cs)
		{
		case(1):
		{

			cs = 0;
			do {
				std::cout << "Добавить пассажира: \n(1)Первого класса.\n(2)Бизнес класса.\n(3)Эконом класса.\nВвод >> ";
				std::cin >> cs;
			} while (cs < 0 || cs > 3);
			switch (cs)
			{
			case(1):
			{
				if (passMaxF != 0) {
					int bag = 0;
					do {
						std::cout << "Введите тоннаж багажа в кг(от 5 до 60)." << std::endl << "Ввод >> ";
						std::cin >> bag;
					} while (bag > 60 || bag < 5);
					sumBag += bag;
					pass++;
					placeF++;
					People* fp = new FirstClassPassenger(bag, placeF);
					board->addUnit(fp);
					airplanePlaces[placeF] = pass - 1;
					passMaxF--;
				}
				else std::cout << "Максимальное кол-во пассажиров первого класса!" << std::endl;
				break;
			}
			case(2):
			{
				if (passMaxB != 0) {
					int bag = 0;
					do {
						std::cout << "Введите тоннаж багажа в кг(от 5 до 60) 35кг бесплатно." << std::endl << "Ввод >> ";
						std::cin >> bag;
					} while (bag > 60 || bag < 5);
					sumBag += bag;
					placeB++;
					People* bp = new FirstClassPassenger(bag, placeB);
					board->addUnit(bp);
					airplanePlaces[placeB] = pass;
					pass++;
					passMaxB--;
				}
				else std::cout << "Максимальное кол-во пассажиров бизнес класса!" << std::endl;
				break;
			}
			case(3):
			{
				if (passMaxE != 0) {
					int bag = 0;
					do {
						std::cout << "Введите тоннаж багажа в кг(от 5 до 60) 20 кг бесплатно." << std::endl << "Ввод >> ";
						std::cin >> bag;
					} while (bag > 60 || bag < 5);
					sumBag += bag;
					baggage[bn] = bag;
					bn++;
					placeE++;
					People* ep = new FirstClassPassenger(bag, placeE);
					board->addUnit(ep);
					airplanePlaces[placeE] = pass;
					pass++;
					passMaxE--;
				}
				else std::cout << "Максимальное кол-во пассажиров эконом класса!" << std::endl;
				break;
			}


			}
			break;
		}
		case(2):
		{
			int delPlace;
			board->getInfo();
			std::cout << "Введите место пассажира, которого хотите удалить. \nВвод >> ";
			std::cin >> delPlace;
			//delPlace -= count;
			if (airplanePlaces[delPlace] != 0) {
				board->deleteUnit(airplanePlaces[delPlace]);
				for (int i = delPlace; i < 180; i++) {
					airplanePlaces[i]--;
				}
				sumBag -= board->getBaggage(airplanePlaces[delPlace]);
				count++;
			}
		}
		case(3):
		{
			board->getInfo();
			break;
		}
		case(4):
		{
			int i = bn;
			while (baggage[i] = 0) i--;
			i--;
			while (maxBag < sumBag) {
				sumBag -= baggage[i];
				board->addUnit(new Baggage(baggage[i]));
				baggage[i] = 0;
				i--;

			}
			break;
		}
		}

	}
	std::cout << "Board>>\n " << std::endl;
	board->getInfo();
	int g = 0;
	std::cin >> g;
	delete board;
	return 0;
}
