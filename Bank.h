//main control panal of the program. It reads the file and executes the program, and prints it.

#pragma once
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include "BST.h"
#include "Transaction.h"
using namespace std;

class Bank
{
public:
	Bank();

	bool readFile(string);
	void startProgram();

private:
	queue<Transaction> transQ {};
	BST accTree;
};

