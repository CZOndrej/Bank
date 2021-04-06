#pragma once
#include <string>
#include <iostream>
#include "Account.h"

using namespace std;

class Client
{
private:
	int code;
	string name;

public:
	Client(int c, string n);

	int GetCode();
	string GetName();
};

