#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
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

bool validateBst(TreeNode* root, int min, int max);

bool validateBst(TreeNode* root)
{
	return validateBst(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

bool validateBst(TreeNode* root, int min, int max)
{
	if (root == nullptr)
	{
		return true;
	}

	if (root->val < min || root->val >= max)
	{
		return false;
	}

	return validateBst(root->left, min, root->val) && validateBst(root->right, root->val, max);
}

int main()
{
	// TODO write test cases

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}
