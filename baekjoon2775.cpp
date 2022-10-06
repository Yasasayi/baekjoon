#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int func(int k, int n);

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int k, n;
		cin >> k >> n;

		cout << func(k, n) << "\n";
	}

	return 0;
}

int func(int k, int n)
{
	int arr[15][15]{ 0 };

	for (int i = 0; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 0)
			{
				arr[i][j] = j;
			}
			else
			{
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
			}
		}
	}

	return arr[k][n];
}