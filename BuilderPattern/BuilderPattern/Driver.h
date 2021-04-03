#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Driver.h"

using namespace std;

class  Driver
{
public:
	virtual void info() {
		cout << "Driver" << endl;
	};
	virtual ~Driver() {}
};

