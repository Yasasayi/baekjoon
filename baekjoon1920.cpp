#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int func(int A[], int num, int start, int end);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int n;
	int m;

	int A[100000]{ 0 };

	int num;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	cin >> m;

	sort(A, A + n);

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cout << func(A, num, 0, n - 1) << "\n";
	}

	return 0;
}

int func(int A[], int num, int start, int end)
{
	int mid = (start + end) / 2;

	if (start > end)
	{
		return 0;
	}

	if (A[mid] < num)
	{
		return func(A, num, mid + 1, end);
	}
	else if (A[mid] > num)
	{
		return func(A, num, start, mid - 1);
	}
	else
	{
		return 1;
	}
}