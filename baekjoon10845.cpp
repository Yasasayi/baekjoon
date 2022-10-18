#include <iostream>
#include <algorithm>

using namespace std;

class queue
{
private:
	int* q;
	int f;
	int b;
public:
	queue(int size) 
	{
		q = new int[size];
		f = 0;
		b = 0;
	}
	
	void push(int n)
	{
		q[b++] = n;
	}

	int pop()
	{
		return empty() ? -1 : q[f++];
	}

	int size()
	{
		return b - f;
	}

	int empty()
	{
		return f == b;
	}

	int front()
	{
		return empty() ? -1 : q[f];
	}

	int back()
	{
		return empty() ? -1 : q[b - 1];
	}

	~queue()
	{
		delete[] q;
	}
};

int main()
{
	int n;
	cin >> n;

	queue q(n);

	for (int i = 0; i < n; i++)
	{
		string op;
		int num;

		cin >> op;

		if (op == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (op == "pop")
		{
			cout << q.pop() << "\n";
		}
		else if (op == "size")
		{
			cout << q.size() << "\n";
		}
		else if (op == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (op == "front")
		{
			cout << q.front() << "\n";
		}
		else if (op == "back")
		{
			cout << q.back() << "\n";
		}
	}

	return 0;
}