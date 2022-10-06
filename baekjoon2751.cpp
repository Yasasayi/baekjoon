#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int num;
	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	
	for (int x : arr)
	{
		cout << x << "\n";
	}

	return 0;
}