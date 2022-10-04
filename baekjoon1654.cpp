#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int func(int k, int n, vector<int> cable, int start, int end);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n;
	cin >> k >> n;

	vector<int> cable;
	int length;

	for (int i = 0; i < k; i++)
	{
		cin >> length;
		cable.push_back(length);
	}

	sort(cable.begin(), cable.end());

	cout << func(k, n, cable, 1, cable[k - 1]) << endl;

	return 0;
}

int func(int k, int n, vector<int> cable, int start, int end)
{
	if (n == 1)
	{
		return end;
	}

	long long cnt = 0;

	long long mid =((long long)start + (long long)end) / 2;

	for (int length : cable)
	{
		cnt += (length / mid);
	}

	if (start > end)
	{
		return mid;
	}

	if (cnt == n)
	{
		int new_cnt = 0;
		for (int length : cable)
		{
			new_cnt += (length / (mid + 1));
		}

		if (cnt == new_cnt)
		{
			return func(k, n, cable, mid + 1, end);
		}
		else
		{
			return mid;
		}
	}
	else if (cnt > n)
	{
		return func(k, n, cable, mid + 1, end);
	}
	else
	{
		return func(k, n, cable, start, mid - 1);
	}
}