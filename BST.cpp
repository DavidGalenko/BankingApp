#include "BST.h"


BST::BST()
{
}


BST::~BST()
{
	Empty();
}

bool BST::Insert(Account* insert)
{
	int insertID = insert->getID();

	if (insertID < 1000 || insertID > 9999)
	{
		cerr << "ERROR: Account ID is not allowed"  << endl;
		return false;
	}

	if (root == nullptr)
	{
		root = new Node;
		root->pAcct = insert;
		root->right = nullptr;
		root->left = nullptr;
		return true;
	}
	else
	{
		RecursiveInsert(root, insert);
	}
	return false;
}

bool BST::Retrieve(const int& ID, Account*& acc) const
{
	Node* temp = root;

	while (true)
	{
		if (temp != nullptr && ID == temp->pAcct->getID())
		{
			acc = temp->pAcct;
			return true;
		}
		else if (temp != nullptr && ID > temp->pAcct->getID())
		{
			temp = temp->right;
		}
		else if (temp != nullptr && ID < temp->pAcct->getID())
		{
			temp = temp->left;
		}
		else
		{
			break;
		}

	}
	cerr << "ERROR: Account " << ID << " not found. Transferal refused." << endl;
	return false;
}
bool BST::RecursiveInsert(Node* temp, Account* insert)
{
	if (insert->getID() > temp->pAcct->getID())
	{
		if (temp->right == nullptr)
		{
			Node* newNode = new Node();
			newNode->pAcct = insert;
			newNode->left = nullptr;
			newNode->right = nullptr;
			temp->right = newNode;
			return true;
		}
		else
		{
			return RecursiveInsert(temp->right, insert);
		}

	}
	else if (insert->getID() < temp->pAcct->getID())
	{
		if (temp->left == nullptr)
		{
			Node* newNode = new Node();
			newNode->pAcct = insert;
			newNode->left = nullptr;
			newNode->right = nullptr;
			temp->left = newNode;
			return true;
		}
		else
		{
			return RecursiveInsert(temp->left, insert);
		}

	}
	else
	{
		cerr << "ERROR: Account " << insert->getID() << " is already open. Transaction refused." << endl;
		return false;
	}

}

void BST::recursiveDisplay(Node* temp) const
{
	if (temp->right != nullptr && temp->left != nullptr)
	{
		cout << *temp->pAcct << endl;
		recursiveDisplay(temp->right);
		recursiveDisplay(temp->left);
	}
	else if (temp->left != nullptr)
	{
		cout << *temp->pAcct << endl;
		recursiveDisplay(temp->left);
	}
	else if (temp->right != nullptr)
	{
		cout << *temp->pAcct << endl;
		recursiveDisplay(temp->right);
	}
	else
	{
		cout << *temp->pAcct << endl;
	}

}

void BST::Display() const
{
	if (root == nullptr)
	{
		cerr << "ERROR: No accounts found" << endl;
	}
	recursiveDisplay(root);
}

void BST::Empty()
{
	delete root;
	root = nullptr;
}

bool BST::isEmpty() const
{
	if (root->left == nullptr && root->right == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
