#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using std::string;
using std::unordered_set;
using std::cout;
using std::cin;

int countSpaces(string chars, int len);

string urlify(string chars, int len)
{
	int spaces = countSpaces(chars, len);
	int end = len - 1 + spaces * 2;
	for (int i = len - 1; i >= 0; --i)
	{
		if (chars[i] == ' ')
		{
			chars[end - 2] = '%';
			chars[end - 1] = '2';
			chars[end] = '0';
			end -= 3;
		}
		else
		{
			chars[end] = chars[i];
			end--;
		}
	}
	return chars;
}

int countSpaces(string chars, int len)
{
	int count = 0;
	for (int i = 0; i < len; ++i)
	{
		if (chars[i] == ' ')
		{
			count++;
		}
	}
	return count;
}

int main()
{
	string chars = "Mr John Smith    ";
	cout << urlify(chars, 13);

	// dummy
	int xxxx = 0;
	cin >> xxxx;

	return 0;
}
