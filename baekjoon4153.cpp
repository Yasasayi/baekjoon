#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void func(int a, int b, int c);

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	while (a != 0 && b != 0 && c != 0)
	{
		func(a, b, c);
		cin >> a >> b >> c;
	}

	return 0;
}

void func(int a, int b, int c)
{
	if (a * a + b * b == c * c)
	{
		cout << "right" << "\n";
	}
	else
	{
		cout << "wrong" << "\n";
	}
}