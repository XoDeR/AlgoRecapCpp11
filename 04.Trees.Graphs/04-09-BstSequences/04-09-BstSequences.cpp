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

void weaveLists(deque<int>& first, deque<int>& second, vector<vector<int>>& results, deque<int>& prefix)
{
	// One list is empty. Add remainder to [a cloned] prefix and store result
	if (first.size() == 0 || second.size() == 0)
	{
		vector<int> result(prefix.begin(), prefix.end());
		result.insert(result.end(), first.begin(), first.end());
		result.insert(result.end(), second.begin(), second.end());
		results.push_back(result);
		return;
	}

	// Recurse with head of first added to the prefix. Removing the head will damage first,
	// so we'll need to put it back where we found it after
	int headFirst = first.front();
	first.pop_front();
	prefix.push_back(headFirst);
	weaveLists(first, second, results, prefix);
	prefix.pop_back();
	first.push_front(headFirst);

	// Do the same thing with second, damaging and then restoring the list
	int headSecond = second.front();
	second.pop_front();
	prefix.push_back(headSecond);
	weaveLists(first, second, results, prefix);
	prefix.pop_back();
	second.push_front(headSecond);

	return;
}

vector<vector<int>> bstSequences(TreeNode* root)
{
	vector<vector<int>> list;
	if (root == nullptr) 
	{
		vector<int> emptyList;
		list.push_back(emptyList);
		return list;
	}

	deque<int> prefix;
	prefix.push_back(root->val);

	vector<vector<int>> leftList = bstSequences(root->left);
	vector<vector<int>> rightList = bstSequences(root->right);

	// Weave together each list from the left and right sides
	for (vector<int> left : leftList)
	{
		for (vector<int> right : rightList)
		{
			vector<vector<int>> weaved;
			weaveLists(deque<int>(left.begin(), left.end()), deque<int>(right.begin(), right.end()), weaved, prefix);
			list.insert(list.end(), weaved.begin(), weaved.end());
		}
	}
	return list;
}

int main()
{
	{
		//           50
		//          /  \
		//         20   60
		//        / \     \
		//       10  25    70
		//      /  \       / \
		//     5    15    65  80
		//
		unique_ptr<TreeNode> a = make_unique<TreeNode>(50);
		unique_ptr<TreeNode> b = make_unique<TreeNode>(20);
		unique_ptr<TreeNode> c = make_unique<TreeNode>(60);
		unique_ptr<TreeNode> d = make_unique<TreeNode>(10);
		unique_ptr<TreeNode> e = make_unique<TreeNode>(25);
		unique_ptr<TreeNode> f = make_unique<TreeNode>(70);
		unique_ptr<TreeNode> g = make_unique<TreeNode>(5);
		unique_ptr<TreeNode> h = make_unique<TreeNode>(15);
		unique_ptr<TreeNode> i = make_unique<TreeNode>(65);
		unique_ptr<TreeNode> j = make_unique<TreeNode>(80);
		a->left = b.get();
		a->right = c.get();
		b->left = d.get();
		b->right = e.get();
		c->right = f.get();
		d->left = g.get();
		d->right = h.get();
		f->left = i.get();
		f->right = j.get();
		vector<vector<int>> lists = bstSequences(a.get());
		for (vector<int>& sequence : lists)
		{
			for (int element : sequence)
			{
				cout << element << '\t';
			}
			cout << '\n';
		}
		cout << '\n';
		cout << '\n';
	}
	{

		//           2
		//          / \
			//         1   3
		//
		unique_ptr<TreeNode> a = make_unique<TreeNode>(2);
		unique_ptr<TreeNode> b = make_unique<TreeNode>(1);
		unique_ptr<TreeNode> c = make_unique<TreeNode>(3);
		a->left = b.get();
		a->right = c.get();
		vector<vector<int>> lists = bstSequences(a.get());
		for (vector<int>& sequence : lists)
		{
			for (int element : sequence)
			{
				cout << element << '\t';
			}
			cout << '\n';
		}
		cout << '\n';
		cout << '\n';
	}

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}

