#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int func(vector<int> trees, int m, int start, int end);
long long calcSum(vector<int> trees, int H);

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> trees;

	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		trees.push_back(h);
	}

	sort(trees.begin(), trees.end());

	cout << func(trees, m, 0, trees.back()) << "\n";

	return 0;
}

long long calcSum(vector<int> trees, int H)
{
	long long sum = 0;

	for (int h : trees)
	{
		if (h > H)
		{
			int height = h - H;
			sum += height;
		}
	}

	return sum;
}

int func(vector<int> trees, int m, int start, int end)
{
	int H = (start + end) / 2;

	if (start > end)
	{
		return H;
	}

	long long sum = calcSum(trees, H);

	if (sum >= m)
	{
		if (calcSum(trees, H + 1) >= m)
		{
			return func(trees, m, H + 1, end);
		}
		else
		{
			return H;
		}
	}
	else
	{
		return func(trees, m, start, H);
	}
}