#include <iostream>
#include <algorithm>

using namespace std;

class stack
{
private:
	int* st;
	int t;
public:
	stack(int size) 
	{
		st = new int[size];
		t = 0;
	}
	
	void push(int n)
	{
		st[t++] = n;
	}

	int pop()
	{
		return empty() ? -1 : st[--t];
	}

	int size()
	{
		return t;
	}

	int empty()
	{
		return t == 0;
	}

	int top()
	{
		return empty() ? -1 : st[t - 1];
	}

	~stack()
	{
		delete[] st;
	}
};

int main()
{
	int n;
	cin >> n;

	stack st(n);

	for (int i = 0; i < n; i++)
	{
		string op;
		int num;

		cin >> op;

		if (op == "push")
		{
			cin >> num;
			st.push(num);
		}
		else if (op == "pop")
		{
			cout << st.pop() << "\n";
		}
		else if (op == "size")
		{
			cout << st.size() << "\n";
		}
		else if (op == "empty")
		{
			cout << st.empty() << "\n";
		}
		else if (op == "top")
		{
			cout << st.top() << "\n";
		}
	}

	return 0;
}