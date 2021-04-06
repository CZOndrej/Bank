#pragma once
#include "Client.h"
#include "Account.h"
class Bank
{
private:
	Client** clients;
	int clientsCount;

	Account** accounts;
	int accountsCount;

public:
	Bank(int c, int a);
	~Bank();

	Client* GetClient(int n);
	Account* GetAccount(int c);

	Client* CreateClient(int c, string n);

	Account* CreateAccount(int n, Client* o);
	Account* CreateAccount(int n, Client* o, double ir);
	Account* CreatePartnerAccount(int n, Client* o, Client* p);
	Account* CreatePartnerAccount(int n, Client* o, Client* p, double ir);

	void AddInterest();
};

