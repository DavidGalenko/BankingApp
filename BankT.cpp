// BankT reads basic bank transactions from a file and executes and prints those actions and the balance in each fund in an account.
// It opens an account, creates 10 funds with 0 balance on each one. It can diposit or withdraw money from a fund.
// It can also transfer money from one fund to the other. Lastly it can print the history of a specified account/fund.
// At the end of the program it will have printed each transation and whether is had an error or not, along with the balances of each fund.

#include <iostream>
#include <fstream>
#include <string>
#include "Transaction.h"
#include "Bank.h"
using namespace std;

int main()
{
    Bank b;
    b.readFile("BankTransIn.txt");
    b.startProgram();
}
