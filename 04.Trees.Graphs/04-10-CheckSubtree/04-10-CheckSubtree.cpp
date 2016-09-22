#include <string>
#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <deque>
using std::unique_ptr;
using std::make_unique;
using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::deque;

struct Node
{
	int val = -1;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(int val)
	{
		this->val = val;
	}
};

bool subTree(Node* T1, Node* T2);

// Larger tree = T1
bool containsTree(Node* T1, Node* T2) 
{
	if (T2 == nullptr)
		return true;
	return subTree(T1, T2);
}

bool matchTree(Node* T1, Node* T2);

// Larger tree = T1
bool subTree(Node* T1, Node* T2) 
{
	if (T1 == nullptr)
		return false;
	else if (T1->val == T2->val && matchTree(T1, T2))
		return true;
	return subTree(T1->left, T2) ||
		subTree(T1->right, T2);
}

bool matchTree(Node* T1, Node* T2) 
{
	if (T1 == nullptr && T2 == nullptr)
		return true;
	else if (T1 == nullptr || T2 == nullptr)
		return false;
	else if (T1->val != T2->val)
		return false;
	else
		return matchTree(T1->left, T2->left) && matchTree(T1->right, T2->right);
}

int main()
{
	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}