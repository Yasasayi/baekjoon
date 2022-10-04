#include <iostream>
#include <algorithm>

using namespace std;

void func(int n);

int main()
{
	int n;

	cin >> n;

	while (n != 0)
	{
		func(n);
		cin >> n;
	}

	return 0;
}

void func(int n)
{
	if (n < 10)
	{
		cout << "yes" << endl;
	}
	else if (n < 100)
	{
		if (n % 10 == n / 10)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	else if (n < 1000)
	{
		if (n % 10 == n / 100)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	else if (n < 10000)
	{
		if (n % 10 == n / 1000 && (n % 100 - n % 10) / 10 == n / 100 - n / 1000 * 10)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	else if (n < 100000)
	{
		if (n % 10 == n / 10000 && (n % 100 - n % 10) / 10 == n / 1000 - n / 10000 * 10)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}