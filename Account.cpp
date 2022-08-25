#include "Account.h"

ostream& operator<<(ostream& out, Account& account)
{
	out << account.getFirst() << " " << account.getLast() << " ID: " << account.getID() << endl;
	for (int i = 0; i < 10; i++)
	{
		out << "    " << account.getFund(i) << ": $" << account.getBalance(i) << endl;
	}

	return out;

}

Account::Account()
{

}

Account::Account(string first, string last, int ID)
{
	first_ = first;
	last_ = last;
	ID_ = ID;

	string funds[] = { "Money Market", "Prime Money Market","Long-Term Bond", "Short-Term Bond","500 Index Fund",
		"Capital Value Fund","Growth Equity Fund", "Growth Index Fund","Value Fund", "Value Stock Index" };
	
	for (int i = 0; i < 10; i < i++)
	{
		arrayFund[i].setName(funds[i]);
	}
}

void Account::AddFund(int fund, int amount)
{
	arrayFund[fund].addAmount(amount);

}

//Checks if fund has a linked fund, if not it proceeds subtract from fund
bool Account::SubFund(Transaction front, int fund, int amount)
{
	if (fund == 0 || fund == 1 || fund == 2 || fund == 3)
	{
		if (fund == 0 || fund == 1)
		{
			if (arrayFund[fund].check(amount))
			{
				arrayFund[fund].subAmount(amount);
				arrayFund[fund].transStore(front);
				return true;
			}
			else if (((arrayFund[0].getBalance() + arrayFund[1].getBalance()) >= amount))
			{
				if (fund == 0)
				{
					LinkedFunds(0, 1, amount);
				}
				else
				{
					LinkedFunds(1, 0, amount);
				}
			}
			else
			{
				cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << getFirst() << " " << getLast() << " " << getFund(fund) << endl;
				Transaction trans('W', getID(), fund, amount, "Failed");
				arrayFund[fund].transStore(trans);

				if (fund == 0)
				{
					LinkedFunds(0, 1, amount);
				}
				else
				{
					LinkedFunds(1, 0, amount);
				}
				return false;
			}
		}
		else if (fund == 2 || fund == 3)
		{
			if (arrayFund[fund].check(amount))
			{
				arrayFund[fund].subAmount(amount);
				arrayFund[fund].transStore(front);
				return true;
			}
			else if (((arrayFund[2].getBalance() + arrayFund[3].getBalance()) >= amount))
			{
				if (fund == 2)
				{
					LinkedFunds(2, 3, amount);
				}
				else
				{
					LinkedFunds(3, 2, amount);
				}
			}
			else
			{
				cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << getFirst() << " " << getLast() << " " << getFund(fund) << endl;
				Transaction trans('W', getID(), fund, amount, "Failed");
				arrayFund[fund].transStore(trans);

				if (fund == 2)
				{
					LinkedFunds(2, 3, amount);
				}
				else
				{
					LinkedFunds(3, 2, amount);
				}
				return false;
			}
		}
	}
	else
	{
		if (arrayFund[fund].check(amount))
		{
			arrayFund[fund].subAmount(amount);
			arrayFund[fund].transStore(front);
			return true;
		}
		else
		{
			cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << getFirst() << " " << getLast() << " " << getFund(fund) << endl;
			Transaction trans('W', getID(), fund, amount, "Failed");
			arrayFund[fund].transStore(trans);
			return false;
		}
	}
}

void Account::TransHistory(Transaction trans, int fundNumber)
{
	arrayFund[fundNumber].transStore(trans);
}

//Withdraw process of linked funds. Checks if there is enough combined then withdraws it   
void Account::LinkedFunds(int f_fund, int s_fund, int amount)
{
	if (((arrayFund[f_fund].getBalance() + arrayFund[s_fund].getBalance()) >= amount))
	{
		int balance = arrayFund[f_fund].getBalance();

		arrayFund[f_fund].subAmount(balance);
		Transaction trans('W', getID(), f_fund, balance);
		arrayFund[f_fund].transStore(trans);

		amount = amount - balance;

		arrayFund[s_fund].subAmount(amount);
		Transaction sTrans('W', getID(), s_fund, amount);
		arrayFund[s_fund].transStore(sTrans);
	}
	else
	{
		int balance = arrayFund[f_fund].getBalance();
		if (balance > amount)
		{
			arrayFund[f_fund].subAmount(balance);
			Transaction trans('W', getID(), f_fund, balance);
			arrayFund[f_fund].transStore(trans);
			amount = amount - balance;
		}

		if (arrayFund[s_fund].check(amount))
		{
			arrayFund[s_fund].subAmount(amount);
			Transaction trans('W', getID(), s_fund, amount);
			arrayFund[s_fund].transStore(trans);
		}
		else
		{
			cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << getFirst() << " " << getLast() << " " << getFund(s_fund) << endl;

			Transaction trans('W', getID(), s_fund, amount, "Failed");
			arrayFund[s_fund].transStore(trans);
		}
	}
}

void Account::PrintHistory()
{
	cout << "Transaction History for " << first_ << " " << last_ << " by fund." << endl;
	for (int i = 0; i < 10; i++)
	{
		arrayFund[i].History();
	}
}

void Account::PrintFundHistory(int fundID)
{
	cout << "Transaction History for " << first_ << " " << last_ << " " << getFund(fundID) << ": $" << getBalance(fundID) << endl;
	arrayFund[fundID].fundHistory();
}



int Account::getID() const
{
	return ID_;
}

int Account::getBalance(int fundNumber)const
{
	return arrayFund[fundNumber].getBalance();
}

string Account::getFund(int fundNumber)
{
	return arrayFund[fundNumber].getName();
}

string Account::getFirst() const
{
	return first_;
}

string Account::getLast() const
{
	return last_;
}

void Account::setFund(int fundNumber)
{
	fund_ = fundNumber;
}
