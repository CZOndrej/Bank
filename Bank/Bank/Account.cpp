#include "Account.h"

Account::Account(int n, Client* o)
{
	this->number = n;
	this->owner = o;
	this->interestRate = 1.2;
	this->balance = 0;
}

Account::Account(int n, Client* o, double ir)
{
	this->number = n;
	this->owner = o;
	this->interestRate = ir;
	this->balance = 0;

}

Account::Account(int n, Client* o, Client* p)
{
	this->number = n;
	this->owner = o;
	this->partner = p;
	this->interestRate = 1.2;
	this->balance = 0;
}

Account::Account(int n, Client* o, Client* p, double ir)
{
	this->number = n;
	this->owner = o;
	this->partner = p;
	this->interestRate = ir;
	this->balance = 0;

}

int Account::GetNumber()
{
	return this->number;
}

double Account::GetBalance()
{
	return this->balance;
}

double Account::GetInterestRate()
{
	return this->interestRate;
}

Client* Account::GetOwner()
{
	return this->owner;
}

Client* Account::GetPartner()
{
	return this->partner;
}

bool Account::CanWithdraw(double a)
{
	if (a<= this->balance)
	{
		return true;
	}
	return false;
}

void Account::Deposit(double a)
{
	this->balance += a;
}

bool Account::Withdraw(double a)
{
	if (CanWithdraw(a))
	{
		this->balance -= a;
		return true;
	}
	return false;
}

void Account::AddInterest()
{
	this->balance += balance * (this->interestRate / 100);
}
