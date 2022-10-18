#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int func(int h, int w, int n);

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int h, w, n;
		cin >> h >> w >> n;
		cout<< func(h, w, n) << "\n";
	}

	return 0;
}

int func(int h, int w, int n)
{
	int y = n % h == 0 ? h * 100 : n % h * 100;
	int x = ceil((double)n / (double)h);

	return y + x;
}