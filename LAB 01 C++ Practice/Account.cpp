#include "Account.h"
#include <iostream>
using namespace std;

Bank::Bank()
{
	name = "";
	acno = 0;
	actype = "";
	balance = 0;
}

void Bank::createAccount()
{
	cout << "New Account" << endl;
	cout << "Enter the Name of the depositor : ";
	cin >> name;
	cout << "Enter the Account Number : ";
	cin >> acno;
	cout << "Enter the Account Type : (CURR / SAVG / FD / RD / DMAT) ";
	cin >> actype;
	cout << "Enter the Amount to Deposit : ";
	cin >> balance;
}

void Bank::deposit()
{
	int amount;
	cout << "Depositing" << endl;
	cout << "Enter the amount to deposit : ";
	cin >> amount;
	balance += amount;
}

void Bank::withdraw()
{
	int amount;
	cout << "Withdrawal" << endl;
	cout << "Enter the amount to withdraw : ";
	cin >> amount;
	balance -= amount;
}

void Bank::printAccount()
{
	cout << "Account Details" << endl;
	cout << "Name of the depositor : " << name << endl;
	cout << "Account Number : " << acno << endl;
	cout << "Account Type : " << actype << endl;
	cout << "Balance : $" << balance << endl;
}