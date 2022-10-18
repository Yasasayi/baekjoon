#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void func(vector<pair<int, int>> students);

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> students;

	for (int i = 0; i < n; i++)
	{
		int weight;
		int height;

		cin >> weight >> height;
		students.push_back(pair<int, int>(weight, height));
	}

	func(students);

	return 0;
}

void func(vector<pair<int, int>> students)
{
	for (pair<int, int> student : students)
	{
		int cnt = 1;

		for (pair<int, int> another : students)
		{
			if (student.first < another.first && student.second < another.second)
			{
				cnt++;
			}
		}

		cout << cnt << " ";
	}

	cout << "\n";
}