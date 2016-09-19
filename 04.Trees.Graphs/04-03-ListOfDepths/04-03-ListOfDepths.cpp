#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::cout;
using std::cin;

class TreeNode
{
public:
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	int val = -1;
	TreeNode(int val)
	{
		this->val = val;
	}
};

vector<vector<TreeNode*>> createList(TreeNode* root)
{
	vector<vector<TreeNode*>> res;

	vector<TreeNode*> current;
	if (root != nullptr)
	{
		current.push_back(root);
	}

	while (current.size() > 0) 
	{
		res.push_back(current);
		vector<TreeNode*> parents = current;

		current.clear();
		for (TreeNode* parent : parents) 
		{
			if (parent->left != nullptr)
			{
				current.push_back(parent->left);
			}
			if (parent->right != nullptr)
			{
				current.push_back(parent->right);
			}
		}
	}
	return res;
}

int main()
{
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	TreeNode* d = new TreeNode(4);
	TreeNode* e = new TreeNode(5);
	TreeNode* f = new TreeNode(6);
	a->left = b;
	a->right = c;
	c->left = d;
	c->right = e;
	e->right = f;
	vector<vector<TreeNode*>> list = createList(a);
	for (vector<TreeNode*> ll : list) 
	{
		for (TreeNode* node : ll)
		{
			cout << node->val << " ";
		}
		cout << "\n";
	}

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}
