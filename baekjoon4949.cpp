#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

void func(string str);

int main()
{
	string str;
	getline(cin, str);

	while (str[0] != '.')
	{
		func(str);
		getline(cin, str);
	}

	return 0;
}

void func(string str)
{
	stack<char> st;

	for (char ch : str)
	{
		if (ch == '(' || ch == '[' || ch == '{')
		{
			st.push(ch);
		}
		else if (ch == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				cout << "no\n";
				return;
			}
			else
			{
				st.pop();
			}
		}
		else if (ch == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				cout << "no\n";
				return;
			}
			else
			{
				st.pop();
			}
		}
		else if (ch == '}')
		{
			if (st.empty() || st.top() != '{')
			{
				cout << "no\n";
				return;
			}
			else
			{
				st.pop();
			}
		}
	}

	if (st.empty())
	{
		cout << "yes\n";
	}
	else
	{
		cout << "no\n";
	}
}