// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
// 
// For example:
// Given the below binary tree and sum = 22,
// 5
// / \
// 4   8
// /   / \
// 11  13  4
// /  \    / \
// 7    2  5   1
// return
// [
// [5,4,11,2],
// [5,8,4,5]
// ]

#include <string>
#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <deque>
#include <queue>
using std::unique_ptr;
using std::make_unique;
using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::deque;
using std::queue;

struct TreeNode
{
	int val = -1;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode(int val)
	{
		this->val = val;
	}
};

int countPathsWithSumFromNode(TreeNode* root, int target, int current);

int countPathsWithSum(TreeNode* root, int sum)
{
	// Note: This is O(n^2). There is another solution with O(n) time + O(n) space complexity

	if (root == nullptr) return 0;

	int pathsFromRoot = countPathsWithSumFromNode(root, sum, 0);

	int pathsOnLeft = countPathsWithSum(root->left, sum);
	int pathsOnRight = countPathsWithSum(root->right, sum);

	return pathsFromRoot + pathsOnLeft + pathsOnRight;
}

int countPathsWithSumFromNode(TreeNode* root, int target, int current)
{
	if (root == nullptr) return 0;

	current += root->val;

	int total = 0;
	if (current == target) 
	{
		total++;
	}

	total += countPathsWithSumFromNode(root->left, target, current);
	total += countPathsWithSumFromNode(root->right, target, current);

	return total;
}

// Recursive
bool hasPathSumRecursive(TreeNode* root, int sum)
{
	if (root == nullptr)
	{
		return false;
	}
	if (root->left == nullptr && root->right == nullptr && sum - root->val == 0)
	{
		return true;
	}
	bool bl = false;
	bool br = false;
	if (root->left != nullptr)
	{
		bl = hasPathSumRecursive(root->left, sum - root->val);
	}
	if (root->right != nullptr)
	{
		br = hasPathSumRecursive(root->right, sum - root->val);
	}
	return bl || br;
}

// Iterative
bool hasPathSumIterative(TreeNode* root, int sum)
{
	if (root == nullptr)
	{
		return false;
	}

	queue<TreeNode*> nodes;
	queue<int> values;

	nodes.push(root);
	values.push(root->val);

	while (!nodes.empty())
	{
		TreeNode* cur = nodes.front();
		nodes.pop();

		int sumVal = values.front();
		values.pop();

		if (cur->left == nullptr && cur->right == nullptr && sumVal == sum)
		{
			return true;
		}

		if (cur->left != nullptr)
		{
			nodes.push(cur->left);
			values.push(sumVal + cur->left->val);
		}

		if (cur->right != nullptr)
		{
			nodes.push(cur->right);
			values.push(sumVal + cur->right->val);
		}
	}
	return false;
}

void getSumRecRecursive(TreeNode* root, int sum, vector<int>& item, vector<vector<int>>& list);

vector<vector<int>> pathSumRecursive(TreeNode* root, int sum)
{
	vector<vector<int>> list;
	if (root == nullptr)
	{
		return list;
	}
	vector<int> item;
	item.push_back(root->val);
	getSumRecRecursive(root, sum - root->val, item, list);
	return list;
}

void getSumRecRecursive(TreeNode* root, int sum, vector<int>& item, vector<vector<int>>& list)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->left == nullptr && root->right == nullptr && sum == 0)
	{
		vector<int> newItem(item);
		list.push_back(newItem);
		return;
	}
	if (root->left != nullptr)
	{
		item.push_back(root->left->val);
		getSumRecRecursive(root->left, sum - root->left->val, item, list);
		item.erase(item.end() - 1);
	}
	if (root->right != nullptr)
	{
		item.push_back(root->right->val);
		getSumRecRecursive(root->right, sum - root->right->val, item, list);
		item.erase(item.end() - 1);
	}
}

int addSumRecursive02(TreeNode* root, int target, vector<int>& item, vector<vector<int>>& list);

vector<vector<int>> pathSumRecursive02(TreeNode* root, int sum)
{
	vector<vector<int>> list;
	vector<int> item;
	addSumRecursive02(root, sum, item, list);
	return list;
}

int addSumRecursive02(TreeNode* root, int target, vector<int>& item, vector<vector<int>>& list)
{
	if (root == nullptr)
	{
		return 0;
	}
	int sum = root->val;
	item.push_back(root->val);
	if (root->left == nullptr && root->right == nullptr)
	{
		if (sum == target)
		{
			list.push_back(item);
		}
		return sum;
	}
	if (root->left != nullptr)
	{
		sum += addSumRecursive02(root->left, target, item, list);
	}
	if (root->right != nullptr)
	{
		sum += addSumRecursive02(root->right, target, item, list);
	}
	return sum;
}

vector<vector<int>> pathSumIterative(TreeNode* root, int sum)
{
	vector<vector<int>> list;
	if (root == nullptr)
	{
		return list;
	}
	queue<TreeNode*> nodes;
	queue<int> values;

	nodes.push(root);
	values.push(root->val);

	vector<int> item;
	while (!nodes.empty())
	{
		TreeNode* cur = nodes.front();
		nodes.pop();
		int sumVal = values.front();
		values.pop();
		item.push_back(cur->val);

		if (cur->left == nullptr && cur->right == nullptr)
		{
			if (sumVal == sum)
			{
				list.push_back(item);
			}
			item.clear();
		}

		if (cur->left != nullptr)
		{
			nodes.push(cur->left);
			values.push(sumVal + cur->left->val);
		}

		if (cur->right != nullptr)
		{
			nodes.push(cur->right);
			values.push(sumVal + cur->right->val);
		}
	}
	return list;
}

int main() 
{
	unique_ptr<TreeNode> a = make_unique<TreeNode>(10);
	unique_ptr<TreeNode> b = make_unique<TreeNode>(5);
	unique_ptr<TreeNode> c = make_unique<TreeNode>(-3);
	unique_ptr<TreeNode> d = make_unique<TreeNode>(3);
	unique_ptr<TreeNode> e = make_unique<TreeNode>(2);
	unique_ptr<TreeNode> f = make_unique<TreeNode>(11);
	unique_ptr<TreeNode> g = make_unique<TreeNode>(3);
	unique_ptr<TreeNode> h = make_unique<TreeNode>(-2);
	unique_ptr<TreeNode> i = make_unique<TreeNode>(1);
	a->left = b.get();
	a->right = c.get();
	b->left = d.get();
	b->right = e.get();
	c->right = f.get();
	d->left = g.get();
	d->right = h.get();
	e->right = i.get();

	cout << countPathsWithSum(a.get(), 8);

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}
