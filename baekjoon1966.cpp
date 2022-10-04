#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void func(queue<pair<int, int>> documents, int M);
queue<pair<int, int>> queueSort(queue<pair<int, int>> documents, queue<pair<int, int>> sorted_q);

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int N, M;
		cin >> N >> M;
		queue<pair<int, int>> documents;

		for (int j = 0; j < N; j++)
		{
			int p;
			cin >> p;
			documents.push(pair<int, int>(j, p));
		}

		func(documents, M);
	}

	return 0;
}

queue<pair<int, int>> queueSort(queue<pair<int, int>> documents, queue<pair<int, int>> sorted_q)
{
	queue<pair<int, int>> q = documents;
	queue<pair<int, int>> sort_sequence;
	queue<pair<int, int>> s_q = sorted_q;

	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();

		if (sort_sequence.empty())
		{
			sort_sequence.push(front);
		}
		else
		{
			if (sort_sequence.front().second >= front.second)
			{
				sort_sequence.push(front);
			}
			else
			{
				while (!sort_sequence.empty())
				{
					q.push(sort_sequence.front());
					sort_sequence.pop();
				}
				sort_sequence.push(front);
			}
		}
	}

	s_q.push(sort_sequence.front());
	sort_sequence.pop();
	
	if (sort_sequence.empty())
	{
		return s_q;
	}

	return queueSort(sort_sequence, s_q);
}

void func(queue<pair<int, int>> documents, int M)
{
	queue<pair<int, int>> q = documents;
	queue<pair<int, int>> sorted_q;

	sorted_q = queueSort(q, sorted_q);

	int i = 1;

	while (!sorted_q.empty())
	{
		if (sorted_q.front().first == M)
		{
			cout << i << "\n";
			break;
		}
		else
		{
			sorted_q.pop();
			i++;
		}
	}
}