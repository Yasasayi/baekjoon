#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

void func(int n, vector<int> nums);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums;

	int num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		nums.push_back(num);
	}

	func(n, nums);

	return 0;
}

void func(int n, vector<int> nums)
{
	int cnt = 0;
	int max = 0;

	vector<string> stack_sequence;
	stack<int> st;

	for (int i = 0; i < n; i++)
	{
		if (cnt < nums[i])
		{
			// push
			for (int j = cnt; j < nums[i]; j++)
			{
				cnt++;
				st.push(cnt);
				stack_sequence.push_back("+\n");
			}

			max = st.top();
		}
		
		if (cnt >= nums[i])
		{
			if (max == nums[i])
			{
				// pop
				st.pop();
				stack_sequence.push_back("-\n");
				if (!st.empty())
				{
					max = st.top();
				}
			}
			else if (max > nums[i])
			{
				cout << "NO\n";
				return;
			}
		}
	}

	for (string str : stack_sequence)
	{
		cout << str;
	}
}