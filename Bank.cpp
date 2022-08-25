#include "Bank.h"

Bank::Bank()
{
}

bool Bank::readFile(string fileName)
{
	string line;
	ifstream in_file;

	in_file.open(fileName);
	if (in_file.is_open())
	{
		while (!in_file.eof())
		{
			getline(in_file, line);

			if (line.empty())
			{
				break;
			}

			istringstream parseLine(line);
			char type;
			parseLine >> type;

			if (type == 'O')
			{
				string first;
				string last;
				int ID;

				parseLine >> last >> first >> ID;

				Transaction addToQueue(type, first, last, ID);
				transQ.push(addToQueue);

			}
			else if (type == 'W'|| type == 'D')
			{
				int ID;
				int fund;
				int amount;

				parseLine >> ID >> amount;
				fund = ID % 10;
				ID = ID / 10;

				Transaction addToQueue(type, ID, fund, amount);
				transQ.push(addToQueue);
			}
			else if (type == 'T')
			{
				int f_ID;
				int f_fund;
				int amount;
				int s_ID; 
				int s_fund;

				parseLine >> f_ID >> amount >> s_ID;
				f_fund = f_ID % 10;
				f_ID = f_ID / 10;
				s_fund = s_ID % 10;
				s_ID = s_ID / 10;

				Transaction addToQueue(type, f_ID, f_fund, amount, s_ID, s_fund);
				transQ.push(addToQueue);
			}
			else if (type == 'H')
			{
				int ID;

				parseLine >> ID;

				Transaction addToQueue(type, ID);
				transQ.push(addToQueue);
			}
		}
		return false;
	}
}
void Bank::startProgram()
{
	while (!transQ.empty())
	{
		Transaction front = transQ.front();

		if (front.getType() == 'O')
		{
			Account* account = new Account(front.getFirst(), front.getLast(), front.getFirstID());
			accTree.Insert(account);
		}
		else if (front.getType() == 'D')
		{
			int ID = front.getFirstID();
			int fund = front.getFirstFund();
			int amount = front.getAmount();
			Account* account;

			if (accTree.Retrieve(ID, account) == true)
			{
				account->AddFund(fund, amount);
				account->TransHistory(front, fund);
			}

		}
		else if (front.getType() == 'W')
		{
			int ID = front.getFirstID();
			int fund = front.getFirstFund();
			int amount = front.getAmount();
			Account* account;

			if (accTree.Retrieve(ID, account) == true)
			{
				account->SubFund(front, fund, amount);
			}

		}
		else if (front.getType() == 'T')
		{
			int f_ID = front.getFirstID();
			int s_ID = front.getSecondID();
			int f_fund = front.getFirstFund();
			int s_fund = front.getSecondFund();
			int amount = front.getAmount();

			Account* curr;
			Account* temp;
			if (accTree.Retrieve(f_ID, curr) && accTree.Retrieve(s_ID, temp))
			{
				if (curr->SubFund(front, f_fund, amount))
				{
					temp->AddFund(s_fund, amount);
					temp->TransHistory(front, s_fund);
				}
				else
				{
					cerr << "ERROR: Not enough funds to transfer  " << amount << " from " << temp->getID() << f_fund << " to " << curr->getID() << s_fund << endl;
					Transaction addToHistory('T', f_ID, f_fund, amount, s_ID, s_fund, "(Failed)");
					temp->TransHistory(addToHistory, s_fund);
				}
			}

		}
		else if (front.getType() == 'H')
		{
			if (front.getFirstID() >= 10000 && front.getFirstID() <= 99999)
			{
				Account* account;
				int fundNumPrt = front.getFirstID() % 10;
				int acctNumSearch = front.getFirstID() / 10;

				if (accTree.Retrieve(acctNumSearch, account))
				{
					account->PrintFundHistory(fundNumPrt);
				}
			}
			else if (front.getFirstID() >= 1000 && front.getFirstID() <= 9999)
			{
				Account* account;
				int acctNumSearch = front.getFirstID();

				if (accTree.Retrieve(acctNumSearch, account))
				{
					account->PrintHistory();
				}
			}
		}
		transQ.pop();
	}
	cout << endl;
	cout << "Processing Done. Final Balances" << endl;
	accTree.Display();
}

