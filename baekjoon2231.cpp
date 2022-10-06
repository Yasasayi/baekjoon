#include <iostream>

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
	int M = 0;

	for (int i = n; i >= 0; i--)
	{
		int sum = i;
		int temp = i;
		
		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == n)
		{
			M = i;
		}
	}

	return M;
}