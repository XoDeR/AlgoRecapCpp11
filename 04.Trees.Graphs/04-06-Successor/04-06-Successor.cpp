#include <string>
#include <iostream>
#include <algorithm>
using std::string;
using std::cout;
using std::cin;

class TreeNode 
{
public:
	int val = -1;
	TreeNode* right = nullptr;
	TreeNode* left = nullptr;
	TreeNode* parent = nullptr;
	TreeNode(int val) 
	{
		this->val = val;
	}
};

TreeNode* leftMostChild(TreeNode* n);

TreeNode* successor(TreeNode* n) 
{
	if (n == nullptr)
	{
		return nullptr;
	}

	if (n->right != nullptr) 
	{
		return leftMostChild(n->right);
	}
	else 
	{
		TreeNode* temp = n;
		TreeNode* parent = n->parent;
		while (parent->right == temp) 
		{
			temp = parent;
			parent = parent->parent;
		}
		return temp;
	}
}

TreeNode* leftMostChild(TreeNode* n) 
{
	if (n == nullptr)
	{
		return nullptr;
	}
	while (n->left != nullptr) 
	{
		n = n->left;
	}
	return n;
}

int main() 
{
	/*        20
	 *       /  \
	 *      10   30
	 *     /  \
	 *    5    15
	 *   / \     \
	 *  3   7     17
	 */
	TreeNode* a = new TreeNode(20);
	TreeNode* b = new TreeNode(10);
	TreeNode* c = new TreeNode(30);
	TreeNode* d = new TreeNode(5);
	TreeNode* e = new TreeNode(15);
	TreeNode* f = new TreeNode(3);
	TreeNode* g = new TreeNode(7);
	TreeNode* h = new TreeNode(17);
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	d->left = f;
	d->right = g;
	e->right = h;
	h->parent = e;
	g->parent = d;
	f->parent = d;
	e->parent = b;
	d->parent = b;
	b->parent = a;
	c->parent = a;

	cout << successor(b)->val << "\n";
	cout << successor(d)->val << "\n";
	cout << successor(a)->val << "\n";

	// dealloc memory
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
	delete h;

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}
