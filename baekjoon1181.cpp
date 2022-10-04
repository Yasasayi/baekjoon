#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void func(vector<vector<string>> arr);
bool compByLength(string a, string b);

int main()
{
	int n;
	cin >> n;

	vector<vector<string>> arr(50);

	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;

		arr[str.length() - 1].push_back(str);
	}

	func(arr);

	return 0;
}

void func(vector<vector<string>> arr)
{
	for (int i = 0; i < 50; i++)
	{
		if (arr.size() > 0)
		{
			// length
			stable_sort(arr[i].begin(), arr[i].end(), compByLength);
			// dict
			stable_sort(arr[i].begin(), arr[i].end());

			arr[i].erase(unique(arr[i].begin(), arr[i].end()), arr[i].end());

			for (string str : arr[i])
			{
				cout << str << endl;
			}
		}
	}
}

bool compByLength(string a, string b)
{
	return a.length() < b.length();
}