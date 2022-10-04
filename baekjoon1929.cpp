#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int prime[1000001];

void func(int m, int n);

int main()
{
	int m;
	int n;

	cin >> m >> n;

	func(m, n);

	return 0;
}

void func(int m, int n)
{
	for (int i = 0; i <= n; i++)
	{
		prime[i] = i;
	}

	for (int i = 2; i <= n; i++)
	{
		if (prime[i] == 1)
		{
			continue;
		}

		for (int j = 2 * i; j <= n; j += i)
		{
			prime[j] = 1;
		}
	}

	for (int i = m; i <= n; i++)
	{
		if (prime[i] != 1)
		{
			cout << prime[i] << "\n";
		}
	}
}