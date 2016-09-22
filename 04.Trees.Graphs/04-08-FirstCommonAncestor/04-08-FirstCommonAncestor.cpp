#include <string>
#include <iostream>
#include <algorithm>
#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::string;
using std::cout;
using std::cin;

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

TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
	if (p == q) return nullptr;

	if (root == q && root == p)
		return root;

	TreeNode* left = commonAncestor(root->left, p, q);
	if (left != nullptr && left != p && left != q)
	{
		return left;
	}

	TreeNode* right = commonAncestor(root->right, p, q);
	if (right != nullptr && right != p && right != q)
	{
		return right;
	}

	if (left != nullptr && right != nullptr)
		return root;
	else if (root == p || root == q)
		return root;
	else
		return left == nullptr ? right : left;
}

int main()
{
	unique_ptr<TreeNode> a = make_unique<TreeNode>(20);
	unique_ptr<TreeNode> b = make_unique<TreeNode>(10);
	unique_ptr<TreeNode> c = make_unique<TreeNode>(30);
	unique_ptr<TreeNode> d = make_unique<TreeNode>(5);
	unique_ptr<TreeNode> e = make_unique<TreeNode>(15);
	unique_ptr<TreeNode> f = make_unique<TreeNode>(3);
	unique_ptr<TreeNode> g = make_unique<TreeNode>(7);
	unique_ptr<TreeNode> h = make_unique<TreeNode>(17);
	a->left = b.get();
	a->right = c.get();
	b->left = d.get();
	b->right = e.get();
	e->right = h.get();
	d->left = f.get();
	d->right = g.get();
	TreeNode* ancestor = commonAncestor(a.get(), g.get(), h.get());
	if (ancestor != nullptr)
	{
		cout << ancestor->val;
	}

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}

