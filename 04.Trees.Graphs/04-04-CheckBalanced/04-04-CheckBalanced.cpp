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

int checkHeight(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int left = checkHeight(root->left);
	if (left == -1)
	{
		return -1;
	}

	int right = checkHeight(root->left);
	if (right == -1)
	{
		return -1;
	}

	int diff = std::abs(left - right);
	if (diff > 1)
	{
		return -1;
	}
	else
	{
		return std::max(left, right) + 1;
	}
}

bool isBalanced(TreeNode* root)
{
	return (checkHeight(root) == -1);
}

int main()
{
	// TODO write test cases
	
	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}
