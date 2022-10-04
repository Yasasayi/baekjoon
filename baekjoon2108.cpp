#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int arr[500000];
int m_cnt[4001]{ 0 };
int p_cnt[4001]{ 0 };

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	int mid = 0;
	int count_max = 0;
	int max = 0;
	int min = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		sum += arr[i];

		if (arr[i] >= 0)
		{
			p_cnt[arr[i]]++;
			if (count_max < p_cnt[arr[i]])
			{
				count_max = p_cnt[arr[i]];
			}
		}
		else
		{
			m_cnt[-arr[i]]++;
			if (count_max < m_cnt[-arr[i]])
			{
				count_max = m_cnt[-arr[i]];
			}
		}

		if (i == 0)
		{
			max = arr[i];
			min = arr[i];
		}
		else
		{
			if (max < arr[i])
			{
				max = arr[i];
			}
		
			if (min > arr[i])
			{
				min = arr[i];
			}
		}
	}

	sort(arr, arr + n);
	mid = arr[n / 2];

	vector<pair<int, int>> cm;

	for (int i = 0; i <= 4000; i++)
	{
		if (p_cnt[i] == count_max)
		{
			cm.push_back(pair<int, int>(i, p_cnt[i]));
		}
		if (m_cnt[i] == count_max)
		{
			cm.push_back(pair<int, int>(-i, m_cnt[i]));
		}
	}
	
	sort(cm.begin(), cm.end(), comp);

	double avg = floor((double)sum / (double)n + 0.5);

	cout << avg << "\n" << mid << "\n";
	if (cm.size() == 1)
	{
		cout << cm[0].first << "\n";
	}
	else
	{
		cout << cm[1].first << "\n";
	}
	cout << max - min << "\n";
	
	return 0;
}