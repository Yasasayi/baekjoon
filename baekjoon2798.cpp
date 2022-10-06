#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int func(vector<int> cards, int m);

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> cards;

	for (int i = 0; i < n; i++)
	{
		int card;
		cin >> card;
		cards.push_back(card);
	}

	sort(cards.begin(), cards.end());

	cout << func(cards, m) << "\n";

	return 0;
}

int func(vector<int> cards, int m)
{
	int sum = cards[0] + cards[1] + cards[2];

	for (int k = 2; k < cards.size(); k++)
	{
		for (int j = 1; j < k; j++)
		{
			for (int i = 0; i < j; i++)
			{
				int temp = cards[i] + cards[j] + cards[k];

				if (temp > sum && temp <= m)
				{
					sum = temp;
				}
			}
		}
	}


	return sum;
}