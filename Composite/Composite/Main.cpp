#include <iostream>
#include <vector>
#include <assert.h>

// Component

class Unit
{
public:
	virtual void getStrength() = 0;

	virtual void addUnit(Unit* p) {

		assert(false);
	}
	virtual ~Unit() {}
};

// Primitives

class Pylot : public Unit
{
public:
	virtual void getStrength() {
		std::cout << "Pylot" << std::endl;
		//return 1;
	}
};

class Stuard : public Unit
{
public:
	virtual void getStrength() {
		std::cout << "Stuard" << std::endl;
		//return 1;
	}
};

class FirstClassPassenger : public Unit
{
public:
	int bag = 0;
	FirstClassPassenger(int b) {
		bag = b;
	}
	virtual void getStrength() {
		//return 1;
		std::cout << "FirstClassPassenger baggage: " << bag << std::endl;
	}
};

class BusinessClassPassenger : public Unit
{
public:
	int bag = 0;
	BusinessClassPassenger(int b) {
		bag = b;
	}
	virtual void getStrength() {
		//return 1;
		std::cout << "BusinessClassPassenger baggage: " << bag << std::endl;
	}
};

class EcoClassPassenger : public Unit
{
public:
	int bag = 0;
	EcoClassPassenger(int b) {
		bag = b;
	}
	virtual void getStrength() {
		//return 1;
		std::cout << "EconomyClassPassenger baggage: " << bag << std::endl;
	}
};

class Baggage : public Unit
{
public:
	int bag = 0;
	Baggage(int b) {
		bag = b;
	}
	virtual void getStrength() {
		//return 1;
		std::cout << "���� � ����� ����� ��������� ������ ������(��): "<< bag << std::endl;
	}
};

// Composite

class CompositeUnit : public Unit
{
public:

	void getStrength() {
		for (int i = 0; i < c.size(); ++i)
			c[i]->getStrength();
			//total += c[i]->getStrength();
	}
	void addUnit(Unit* p) {

		c.push_back(p);

	}

	~CompositeUnit() {

		for (int i = 0; i < c.size(); ++i)
			delete c[i];

	}

private:

	std::vector<Unit*> c;

};

// ��������������� ������� ��� �������� �����

CompositeUnit* createBoard()

{
	// ���� ��������:
	CompositeUnit* board = new CompositeUnit;

	// 2 ������
	for (int i = 0; i < 2; i++) 
		board->addUnit(new Pylot);
	
	//2 �������
	for (int i = 0; i < 6; i++)
		board->addUnit(new Stuard);

	//�� 10 ���������� �������, ������ (����. 20 ���) � ������ (150 ���) classov.
	int cs = 0, pass = 0, sumBag = 0, maxBag = 100, bn = 0;
	int passMaxF = 10, passMaxB = 20, passMaxE = 150;
	int* baggage = new int[150];
	
	while (cs != 4) {
		cs = 0;
		do {
			std::cout << "�������� ���������: \n(1)������� ������.\n(2)������ ������.\n(3)������ ������.\n\n(4)�����������.\n\n���� >> ";
			std::cin >> cs;
		} while (cs < 0 || cs > 4);
		switch (cs)
		{
		case(1):
		{
			if (passMaxF != 0) {
				int bag = 0;
				do {
					std::cout << "������� ������ ������ � ��(�� 5 �� 60)." << std::endl << "���� >> ";
					std::cin >> bag;
				} while (bag > 60 || bag < 5);
				sumBag += bag;
				pass++;

				board->addUnit(new FirstClassPassenger(bag));
				std::cout << "�������� ��������\n\n" << std::endl;
				passMaxF--;
			}
			else std::cout << "������������ ���-�� ���������� ������� ������!" << std::endl;

			break;
		}
		case(2):
		{
			if (passMaxB != 0) {
			int bag = 0;
			do {
				std::cout << "������� ������ ������ � ��(�� 5 �� 60) 35�� ���������." << std::endl << "���� >> ";
				std::cin >> bag;
			} while (bag > 60 || bag < 5);
			sumBag += bag;
			pass++;
			
			board->addUnit(new BusinessClassPassenger(bag));
			std::cout << "�������� ��������\n\n" << std::endl;
			passMaxB--;
			}
			else std::cout << "������������ ���-�� ���������� ������ ������!" << std::endl;
			break;
		}
		case(3):
		{
			if(passMaxE != 0){
			int bag = 0;
			do {
				std::cout << "������� ������ ������ � ��(�� 5 �� 60) 20 �� ���������." << std::endl << "���� >> ";
				std::cin >> bag;
			} while (bag > 60 || bag < 5);
			sumBag += bag;
			pass++;
			baggage[bn] = bag;
			bn++;
			board->addUnit(new EcoClassPassenger(bag));
			std::cout << "�������� ��������" << std::endl;
			std::cout << "����� ������:"<< sumBag << "\n\n" <<std::endl;
			passMaxE--;
		}
			else std::cout << "������������ ���-�� ���������� ������ ������!" << std::endl;
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
	return board;

}

int main()
{
	setlocale(LC_ALL, "Russian");
	CompositeUnit* board = new CompositeUnit;
	board->addUnit(createBoard());
	std::cout << "Board>>\n " << std::endl;
	board->getStrength();
	int g = 0;
	std::cin >> g;
	delete board;
	return 0;
}