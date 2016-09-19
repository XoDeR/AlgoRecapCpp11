#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using std::string;
using std::unordered_set;
using std::cout;
using std::cin;

bool isPermutation(string a, string b) 
{
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	if (a.size() != b.size())
	{
		return false;
	}
	for (int i = 0; i < a.size(); ++i) 
	{
		if (a[i] != b[i])
		{
			return false;
		}
    }
    return true;
}

int main() 
{
	cout << "abc" << ", " <<  "cba" << " :" << (isPermutation("abc", "cba") ? "It is a permutation" : "It is not a permutation") << '\n';
    cout << (isPermutation("test", "estt") ? "It is a permutation" : "It is not a permutation") << '\n';
    cout << (isPermutation("testt", "estt") ? "It is a permutation" : "It is not a permutation") << '\n';

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}
