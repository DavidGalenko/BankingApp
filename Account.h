//Keeps track of everything the happens in an account with each transaction and prints it

#pragma once
#include "Transaction.h"
#include "Fund.h"
#include <string>
using namespace std;


class Account
{
	friend ostream& operator << (ostream&, Account&);

public:
	Account();
	Account(string, string, int);

	void AddFund(int, int);
	bool SubFund(Transaction, int, int);
	void TransHistory(Transaction, int);
	void LinkedFunds(int, int, int);
	void PrintHistory();
	void PrintFundHistory(int);

	int getID() const;
	int getBalance(int)const;
	string getFund(int);
	string getFirst() const;
	string getLast()const;
	void setFund(int);

private:
	string first_, last_;
	int ID_, fund_;
	Fund arrayFund[10];
};
