#include <iostream>
#include <queue>

using namespace std;

void func(int n);

int main()
{
	int n;
	cin >> n;
	
	func(n);

	return 0;
}

void func(int n)
{
	queue<int> deck;

	for (int i = 1; i <= n; i++)
	{
		deck.push(i);
	}

	while (deck.size() > 1)
	{
		deck.pop();
		deck.push(deck.front());
		deck.pop();
	}

	cout << deck.front() << "\n";
}