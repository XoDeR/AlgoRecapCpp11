#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <vector>
using std::string;
using std::vector;
using std::unordered_set;
using std::cout;
using std::cin;

class Pair
{
public:
	int p1;
	int p2;
	Pair(int p1, int p2)
		: p1(p1)
		, p2(p2)
	{
	}
};

vector<Pair> getPairs(vector<int>& nums, int sum)
{
	vector<Pair> lst;
	unordered_set<int> set;

	for (int i = 0; i < nums.size(); ++i) 
	{
		int current = nums[i];

		auto it = set.find(current);
		if (it != set.end())
		{
			lst.push_back(Pair(sum - current, current));
		} 
		else
		{
			set.insert(sum - current);
		}
	}
	return lst;
}

int main()
{
	vector<int> nums =
	{ 1, 4, 2, 5, 6, 7, 0, 3 };
	int sum = 7;

	vector<Pair> list = std::move(getPairs(nums, sum));
	for (Pair& pair : list)
	{
		cout << std::to_string(pair.p1) << " : " << std::to_string(pair.p2) << '\n';
	}
		
	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}