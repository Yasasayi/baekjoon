#include <iostream>
#include <algorithm>

using namespace std;

void func(int n);

int main()
{
	int n;
	cin >> n;

	func(n);

	return 0;
}

void func(int n)
{
	int cnt = 0;
	int result = 0;
	int temp = 0;

	while (cnt != n)
	{
		result++;
		temp = result;

		while (temp != 0)
		{
			if (temp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else
			{
				temp /= 10;
			}
		}
	}

	cout << result << endl;
}