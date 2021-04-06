
#include <iostream>
#include "Bank.h"
#include "Account.h"
#include "PartnerAccount.h"
#include "Client.h"

using namespace std;

Bank::Bank(int c, int a)
{
    this->clients = new Client * [c];
    this->accounts = new Account * [a];

    this->accountsCount = 0;
    this->clientsCount = 0;
}

Bank::~Bank()
{
    for (int i = 0; i < clientsCount; i++)
    {
        delete clients[i];
    }
    for (int i = 0; i < accountsCount; i++)
    {
        delete accounts[i];
    }
    delete[] clients;
    delete[] accounts;
}

Client* Bank::GetClient(int n)
{
    for (int i = 0; i < this->clientsCount; i++)
    {
        if (clients[i]->GetCode() == n)
        {
            return clients[i];
        }
    }
    return nullptr;
}

Account* Bank::GetAccount(int c)
{
    for (int i = 0; i < this->clientsCount; i++)
    {
        if (accounts[i]->GetNumber() == c)
        {
            return accounts[i];
        }
    }
    return nullptr;
}

Client* Bank::CreateClient(int c, string n)
{
    Client* newClient = new Client(c, n);
    clients[clientsCount] = newClient;
    clientsCount++;
    return newClient;
}

Account* Bank::CreateAccount(int n, Client* o)
{
    Account* newAccount = new Account(n ,o);
    accounts[accountsCount] = newAccount;
    accountsCount++;
    return newAccount;
}

Account* Bank::CreateAccount(int n, Client* o, double ir)
{
    Account* newAccount = new Account(n, o, ir);
    accounts[accountsCount] = newAccount;
    accountsCount++;
    return newAccount;
}

Account* Bank::CreatePartnerAccount(int n, Client* o, Client* p)
{
    PartnerAccount* newAccount = new PartnerAccount(n, o, p);
    accounts[accountsCount] = newAccount;
    accountsCount++;
    return newAccount;
}

Account* Bank::CreatePartnerAccount(int n, Client* o, Client* p, double ir)
{
    PartnerAccount* newAccount = new PartnerAccount(n, o, p, ir);
    accounts[accountsCount] = newAccount;
    accountsCount++;
    return newAccount;
}

void Bank::AddInterest()
{
    for (int i = 0; i < accountsCount; i++)
    {
        accounts[i]->AddInterest();
    }
}
