//Binary Search Tree that stores and prints out each account

#pragma once
#include <iostream>
using namespace std;
#include "Account.h"

class BST
{
private:
	struct Node
	{
		Account* pAcct;
		Node* right;
		Node* left;
	};
	Node* root = NULL;
public:

	BST();
	~BST();

	bool Insert(Account*);
	bool Retrieve(const int&, Account*&) const;
	bool RecursiveInsert(Node*, Account*);
	void recursiveDisplay(Node*) const;

	void Display() const;
	void Empty();
	bool isEmpty() const;

};

