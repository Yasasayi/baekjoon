#include <iostream>
#include <algorithm>

using namespace std;

int m_arr[10000001]{ 0 };
int p_arr[10000001]{ 0 };
int arr[500000]{ 0 };

void func(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		if (arr[i] >= 0)
		{
			p_arr[arr[i]]++;
		}
		else
		{
			m_arr[-arr[i]]++;
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		func(num);
	}

	return 0;
}

void func(int n)
{
	if (n >= 0)
	{
		cout << p_arr[n] << " ";
	}
	else
	{
		cout << m_arr[-n] << " ";
	}
}