#pragma once
#include <string>
#include <iostream>
#include "Client.h"

using namespace std;

class Account
{
private:
	int number;
	double balance;
	double interestRate;
	static int accountObjects;

	Client* owner;

public:
	Account(int n, Client* o);
	Account(int n, Client* o, double ir);

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client* GetOwner();
	bool CanWithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();
	static int GetAccountsObjCount();
};

