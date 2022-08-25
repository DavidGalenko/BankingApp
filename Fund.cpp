#include "Fund.h"


Fund::Fund()
{
	balance = 0;
}


bool Fund::addAmount(int amountIn)
{
	balance += amountIn;
	return true;
}

bool Fund::subAmount(int amountToSub)
{
	balance -= amountToSub;
	return true;
}

bool Fund::check(int amountToSub)
{
	if (balance >= amountToSub)
	{
		return true;
	}
	return false;
}


bool Fund::transStore(Transaction tran)
{
	trans.push_back(tran);
	return true;
}

void Fund::fundHistory()
{
	for (int i = 0; i < trans.size(); i++)
	{
		cout << " " << trans[i];
	}
}

void Fund::History()
{
	if (trans.size() == 0)
	{
		return;
	}
	else
	{
		cout << fundName << ": $" << balance << endl;
		for (int i = 0; i < trans.size(); i++)
		{
			cout << " " << trans[i];
		}
	}
}

void Fund::setName(string name)
{
	this->fundName = name;
}

int Fund::getBalance() const
{
	return balance;
}

string Fund::getName() const
{
	return fundName;
}
