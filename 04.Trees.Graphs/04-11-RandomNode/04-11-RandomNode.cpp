#include <string>
#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <deque>
#include <random>
using std::unique_ptr;
using std::make_unique;
using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::deque;

std::default_random_engine & globalUrng()
{
	static std::default_random_engine u{};
	return u;
}
void randomize()
{
	static std::random_device rd{};
	globalUrng().seed(rd());
}
int pickNumber(int from, int thru)
{
	static std::uniform_int_distribution<> d{};
	using parm_t = std::uniform_int_distribution<>::param_type;
	return d(globalUrng(), parm_t{ from, thru });
}

struct TreeNode
{
	int val = -1;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	int size = 0;


	TreeNode(int val)
	{
		this->val = val;
		size = 1;
	}

	TreeNode* getRandomNode()
	{
		int leftSize = (left == nullptr ? 0 : left->size);
		int index = pickNumber(0, size);
		if (index < leftSize)
		{
			if (left != nullptr)
			{
				return left->getRandomNode();
			}
		}
		else if (index == leftSize)
			return this;
		else
		{
			if (right != nullptr)
			{
				return right->getRandomNode();
			}
		}
		return this;
	}
};

int main()
{
	randomize();

	unique_ptr<TreeNode> a = make_unique<TreeNode>(8);
	unique_ptr<TreeNode> b = make_unique<TreeNode>(4);
	unique_ptr<TreeNode> c = make_unique<TreeNode>(13);
	unique_ptr<TreeNode> d = make_unique<TreeNode>(2);
	unique_ptr<TreeNode> e = make_unique<TreeNode>(6);
	a->left = b.get();
	a->right = c.get();
	b->left = d.get();
	b->right = e.get();
	a->size = 5;
	b->size = 3;

	cout << a->getRandomNode()->val << '\t';
	cout << a->getRandomNode()->val << '\t';
	cout << a->getRandomNode()->val << '\t';
	cout << a->getRandomNode()->val << '\t';
	cout << a->getRandomNode()->val << '\t';

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}
