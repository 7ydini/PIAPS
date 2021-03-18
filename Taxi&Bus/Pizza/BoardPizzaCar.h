#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "AbstractFactory/BoardAnyCar.h"

using namespace std;

class BoardPizzaCar : public BoardAnyCar
{
public:
	int pasMax = 20;
	void info() {
		cout << "Pizza" << endl;
	}
};