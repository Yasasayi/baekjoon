#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void func(string str);

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		func(str);
	}

	return 0;
}

void func(string str)
{
	stack<char> st;

	for (char ch : str)
	{
		if (ch == '(')
		{
			st.push(ch);
		}
		else if (ch == ')')
		{
			if (st.empty())
			{
				cout << "NO\n";
				return;
			}
			else
			{
				st.pop();
			}
		}
	}

	if (!st.empty())
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
	}
}