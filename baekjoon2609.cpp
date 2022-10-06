#include <iostream>

using namespace std;

void func(int a, int b);

int main()
{
	int a, b;
	cin >> a >> b;
	
	func(a, b);

	return 0;
}

void func(int a, int b)
{
	int gcd = 0;
	int lcm = 0;

	int x = a;
	int y = b;

	int mod = -1;

	while (mod != 0)
	{
		mod = x % y;
		x = y;
		y = mod;
	}

	gcd = x;
	lcm = a * b / x;

	cout << gcd << "\n" << lcm << "\n";
}