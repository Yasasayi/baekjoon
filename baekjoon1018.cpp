#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

void func(int n, int m, int i, int j, char arr[50][50]);
int bfs(int i, int j, char arr[50][50], bool visited[8][8]);

int minimum = 100;

int main()
{
	int n, m;
	cin >> n >> m;

	char arr[50][50]{ '0' };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	func(n, m, 0, 0, arr);

	cout << minimum << endl;

	return 0;
}

void func(int n, int m, int i, int j, char arr[50][50])
{
	
	bool visited[8][8]{ false };
	int cnt = bfs(i, j, arr, visited);

	minimum = min(minimum, cnt);

	// brute force
	if (n > 8 || m > 8)
	{
		for (int i = 0; i + 7 < n; i++)
		{
			for (int j = 0; j + 7 < m; j++)
			{
				func(8, 8, i, j, arr);
			}
		}
	}
}

int bfs(int i, int j, char arr[50][50], bool visited[8][8])
{
	int cnt1 = 0;
	int cnt2 = 0;

	int cur_i = i;
	int cur_j = j;

	char board[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = arr[cur_i + i][cur_j + j];
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push(pair<pair<int, int>, int>(pair<int, int>(0, 0), 0));
	visited[0][0] = true;

	while (!q.empty())
	{
		cur_i = q.front().first.first;
		cur_j = q.front().first.second;
		char color = board[cur_i][cur_j];
		int height = q.front().second;
		q.pop();

		if (board[0][0] == 'W')
		{
			if (height % 2 == 0)
			{
				if (color == 'B')
				{
					cnt1++;
				}
				else if (color == 'W')
				{
					cnt2++;
				}
			}
			else
			{
				if (color == 'W')
				{
					cnt1++;
				}
				else if (color == 'B')
				{
					cnt2++;
				}
			}
		}
		else if (board[0][0] == 'B')
		{
			if (height % 2 == 0)
			{
				if (color == 'W')
				{
					cnt1++;
				}
				else if (color == 'B')
				{
					cnt2++;
				}
			}
			else
			{
				if (color == 'B')
				{
					cnt1++;
				}
				else if (color == 'W')
				{
					cnt2++;
				}
			}
		}

		// right
		if (cur_j < 7 && !visited[cur_i][cur_j + 1])
		{
			q.push(pair<pair<int, int>, int>(pair<int, int>(cur_i, cur_j + 1), height + 1));
			visited[cur_i][cur_j + 1] = true;
		}
		// down
		if (cur_i < 7 && !visited[cur_i + 1][cur_j])
		{
			q.push(pair<pair<int, int>, int>(pair<int, int>(cur_i + 1, cur_j), height + 1));
			visited[cur_i + 1][cur_j] = true;
		}
	}

	return min(cnt1, cnt2);
}