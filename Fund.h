//Does every action needed for each fund whether is adding, subtracting, printing, etc.

#pragma once
#include "Transaction.h"
#include <vector>

class Fund
{
public:
	Fund();

	bool addAmount(int);
	bool subAmount(int);
	bool check(int);
	bool transStore(Transaction);
	void fundHistory();
	void History();
	void setName(string);
	int getBalance() const;
	string getName() const;


private:
	int balance = 0;
	string fundName;
	vector<Transaction> trans;
};