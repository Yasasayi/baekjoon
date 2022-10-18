#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, string>> people;

	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		
		cin >> age >> name;
		people.push_back(pair<int, string>(age, name));
	}

	stable_sort(people.begin(), people.end(), comp);

	for (pair<int, string> person : people)
	{
		cout << person.first << " " << person.second << "\n";
	}

	return 0;
}