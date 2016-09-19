#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using std::string;
using std::unordered_set;
using std::cout;
using std::cin;

bool isUniqueUsingHash(string word) 
{
	bool result = true;
	unordered_set<char> charSet;
	for (char c : word)
	{
		auto foundIt = charSet.find(c);
		if (foundIt != charSet.end())
		{
			result = false;
			return result;
		}
		else 
		{
			charSet.insert(c);
		}
	}
	return result;
}

bool isUniqueUsingSort(string word) 
{
	bool result = true;

	if (word.size() <= 1)
	{
		result = true;
		return result;
	}

	std::sort(word.begin(), word.end());
	char temp = word[0];
	for (int i = 1; i < word.size(); ++i)
	{
		if (word[i] == temp)
		{
			result = false;
			return result;
		}
		temp = word[i];
	}
	return result;
}

int main() 
{
	cout << "Word" << ' ' << (isUniqueUsingHash("Word") ? "Unique" : "Not Unique") << '\n';
	cout << "Nootunique" << ' ' << (isUniqueUsingSort("Nootunique") ? "Unique" : "Not Unique") << '\n';

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}
