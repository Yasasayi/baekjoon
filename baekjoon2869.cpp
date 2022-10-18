#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int func(int a, int b, int v);

int main()
{
	int a, b, v;
	cin >> a >> b >> v;

	cout << func(a, b, v) << "\n";

	return 0;
}

int func(int a, int b, int v)
{
	int h = v - a;
	int day = ceil((double)h / ((double)a - (double)b)) + 1;

	return day;
}