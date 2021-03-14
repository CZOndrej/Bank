#include "Account.h"
#include "Bank.h"
#include "Client.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Bank* bank = new Bank(200, 200);

	for (int i = 0; i < 150; i++)
	{
		bank->CreateClient(i, "name" + to_string(i));
	}

	for (int i = 0; i < 150; i++)
	{
		bank->CreateAccount(i + 100, bank->GetClient(i));
		bank->GetAccount(i + 100)->Deposit(i * 100);
	}

	cout << bank->GetAccount(115)->GetBalance()<<endl;

	bank->AddInterest();

	cout << bank->GetAccount(115)->GetBalance()<<endl;

	delete bank;
	cin.get();

	

}