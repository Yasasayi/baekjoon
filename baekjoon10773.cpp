#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int func(int n);

int main()
{
	int k;
	cin >> k;

	cout << func(k) << "\n";

	return 0;
}

int func(int k)
{
	int sum = 0;
	stack<int> st;

	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;

		if (n == 0)
		{
			st.pop();
		}
		else
		{
			st.push(n);
		}
	}

	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}

	return sum;
}