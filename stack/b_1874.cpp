#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int	main()
{
	stack<int>	stack;
	queue<char>	q;
	int			n, m, tmp;

	tmp = 1;
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin >> m;
		if (tmp <= m)
		{
			for (tmp; tmp <= m; tmp ++)
			{
				q.push('+');
				stack.push(tmp);
			}
			q.push('-');
			stack.pop();
		}
		else
		{
			if (stack.top() != m)
			{
				cout << "NO";
				return (0);
			}
			else 
			{
				q.push('-');
				stack.pop();
			}
		}
	}
	while(!q.empty())
	{
		cout << q.front() << '\n';
		q.pop();
	}
}