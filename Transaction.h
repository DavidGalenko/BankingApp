// takes in trasaction type through the constructor and assigns to the values to be used by other classes

#pragma once
#include <iostream>
using namespace std;

class Transaction
{
	friend ostream& operator<<(ostream& out, const Transaction& trans);
public:
	Transaction();
	Transaction(char, int);
	Transaction(char, int, int);
	Transaction(char, int, int, int);
	Transaction(char, string, string, int);
	Transaction(char, int, int, int, string);
	Transaction(char, int, int, int, int, int);
	Transaction(char, int, int, int, int, int, string);


	char getType() const;
	string getFirst() const;
	string getLast() const;
	int getFirstID() const;
	int getFirstFund() const;
	int getSecondID() const;
	int getSecondFund() const;
	int getAmount() const;


private:
	char type_;
	string first_, last_, test_;
	int f_ID_, f_fund_, s_ID_, s_fund_, amount_;
};

