#include <iostream>
#include <stack>

using namespace std;

int	main(void)
{
	stack<int>	stack;
	int			tmp, res;
	int			n;

	res = 0;
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin >> tmp;
		res += tmp;
		if (tmp != 0)
			stack.push(tmp);
		else
		{
			res -= stack.top();
			stack.pop();
		}
	}
	cout << res;
}