#include <iostream>
#include <algorithm>

using namespace std;

int func(int n);

int main()
{
	int n;
	cin >> n;

	cout << func(n) << "\n";

	return 0;
}

int func(int n)
{
	int dp[1001]{ 0 };
	int min = -1;

	for (int i = 0; i <= n / 5; i++)
	{
		dp[i] = i + (n - i * 5) / 3;

		if ((n - i * 5) % 3 == 0)
		{
			if (min == -1 || min > dp[i])
			{
				min = dp[i];
			}
		}
	}

	return min;
}