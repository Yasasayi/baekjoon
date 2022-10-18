#include <iostream>
#include <algorithm>

using namespace std;

class deque
{
private:
	int* q;
	int f;
	int b;
	int s;
	int max_s;
public:
	deque(int size) 
	{
		q = new int[size];
		f = 0;
		b = 1;
		s = 0;
		max_s = size;
	}
	
	void push_front(int n)
	{
		q[f] = n;
		f = (f - 1 + max_s) % max_s;
		s++;
	}

	void push_back(int n)
	{
		q[b] = n;
		b = (b + 1 + max_s) % max_s;
		s++;
	}

	int pop_front()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			f = (f + 1 + max_s) % max_s;
			s--;
			return q[f];
		}
	}

	int pop_back()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			b = (b - 1 + max_s) % max_s;
			s--;
			return q[b];
		}
	}

	int size()
	{
		return s;
	}

	int empty()
	{
		return s == 0;
	}

	int front()
	{
		return empty() ? -1 : q[(f + 1 + max_s) % max_s];
	}

	int back()
	{
		return empty() ? -1 : q[(b - 1 + max_s) % max_s];
	}

	~deque()
	{
		delete[] q;
	}
};

int main()
{
	int n;
	cin >> n;

	deque q(n);

	for (int i = 0; i < n; i++)
	{
		string op;
		int num;

		cin >> op;

		if (op == "push_front")
		{
			cin >> num;
			q.push_front(num);
		}
		else if (op == "push_back")
		{
			cin >> num;
			q.push_back(num);
		}
		else if (op == "pop_front")
		{
			cout << q.pop_front() << "\n";
		}
		else if (op == "pop_back")
		{
			cout << q.pop_back() << "\n";
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