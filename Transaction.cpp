#include "Transaction.h"

ostream& operator<<(ostream& out, const Transaction& trans)
{
	if (trans.test_.empty())
	{
		if (trans.getType() == 'D' || trans.getType() == 'W')
		{
			out << "   " << trans.getType() << " " << trans.getFirstID() << trans.getFirstFund() << " " << trans.getAmount() << endl;
		}
		else if (trans.getType() == 'T')
		{
			out << "   " << trans.getType() << " " << trans.getFirstID() << trans.getFirstFund() << " " 
				<< trans.getAmount() << " " << trans.getSecondID() << trans.getSecondFund() << endl;
		}
	}
	else
	{
		if (trans.getType() == 'D' || trans.getType() == 'W')
		{
			out << "   " << trans.getType() << " " << trans.getFirstID() << trans.getFirstFund() << " " << trans.getAmount() << " (Failed)" << endl;
		}
		else if (trans.getType() == 'T')
		{
			out << "   " << trans.getType() << " " << trans.getFirstID() << trans.getFirstFund() << " " 
				<< trans.getAmount() << " " << trans.getSecondID() << trans.getSecondFund() << "(Failed)" << endl;
		}

	}
	return out;

}

Transaction::Transaction()
{
	type_ = NULL;
	first_ = "";
	last_ = "";
	f_ID_ = 0;
	f_fund_ = 0;
	s_ID_ = 0;
	s_fund_ = 0;
	amount_ = 0;
}

Transaction::Transaction(char type, int account)
{
	type_ = type;
	f_ID_ = account;
}

Transaction::Transaction(char type, int account, int fund)
{
	type_ = type;
	f_ID_ = account;
	f_fund_ = fund;

}

Transaction::Transaction(char type, int account, int fund, int amount)
{
	type_ = type;
	f_ID_ = account;
	f_fund_ = fund;
	amount_ = amount;
}

Transaction::Transaction(char type, string firstName, string lastName, int account)
{
	type_ = type;
	first_ = firstName;
	last_ = lastName;
	f_ID_ = account;
}


Transaction::Transaction(char type, int account, int fund, int amount, string test)
{
	type_ = type;
	f_ID_ = account;
	f_fund_ = fund;
	amount_ = amount;
	test_= test;
}

Transaction::Transaction(char type, int firstAccount, int firstFund, int amount, int secondAccount, int secondFund)
{
	type_ = type;
	f_ID_ = firstAccount;
	f_fund_ = firstFund;
	amount_ = amount;
	s_ID_ = secondAccount;
	s_fund_ = secondFund;
}

Transaction::Transaction(char type, int firstAccount, int firstFund, int amount, int secondAccount, int secondFund, string test)
{
	type_ = type;
	f_ID_ = firstAccount;
	f_fund_ = firstFund;
	amount_ = amount;
	s_ID_ = secondAccount;
	s_fund_ = secondFund;
	test_ = test;
}

char Transaction::getType() const
{
	return type_;
}

string Transaction::getFirst() const
{
	return first_;
}

string Transaction::getLast() const
{
	return last_;
}

int Transaction::getFirstID() const
{
	return f_ID_;
}

int Transaction::getFirstFund() const
{
	return f_fund_;
}

int Transaction::getSecondID() const
{
	return s_ID_;
}

int Transaction::getSecondFund() const
{
	return s_fund_;
}

int Transaction::getAmount() const
{
	return amount_;
}

