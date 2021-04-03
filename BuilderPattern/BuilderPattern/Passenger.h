#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class  Passenger
{
public:
	virtual void info() {
		cout << "Passennger" << endl;
	};
	virtual ~Passenger() {}
};

