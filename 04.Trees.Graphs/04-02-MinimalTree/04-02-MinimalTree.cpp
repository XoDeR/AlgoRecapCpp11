#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::unordered_set;
using std::cout;
using std::cin;

class Node 
{
public:
	int key = -1;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(int a) 
	{
		this->key = a;
	}
};

Node* createBst(vector<int>& intList, int start, int end);

Node* createBst(vector<int>& intList) 
{
	return createBst(intList, 0, intList.size() - 1);
}

Node* createBst(vector<int>& intList, int start, int end)
{
	if (end < start)
	{
		return nullptr;
	}

	int mid = start + ((end - start) / 2);

	Node* node = new Node(intList[mid]);
	node->left = createBst(intList, start, mid - 1);
	node->right = createBst(intList, mid + 1, end);
	return node;
}

void inOrderTraversalPrint(Node* node)
{
	if (node != nullptr)
	{
		inOrderTraversalPrint(node->left);
		cout << node->key << "\t";
		inOrderTraversalPrint(node->right);
	}
}

void postOrderTraversalDeAlloc(Node* node)
{
	if (node != nullptr)
	{
		postOrderTraversalDeAlloc(node->left);
		postOrderTraversalDeAlloc(node->right);
		delete node;
	}
}

int main()
{
	vector<int> intList = 
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};
	Node* root = createBst(intList);

	inOrderTraversalPrint(root);

	// dealloc memory for the tree

	// use post-order traversal
	postOrderTraversalDeAlloc(root);

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}

