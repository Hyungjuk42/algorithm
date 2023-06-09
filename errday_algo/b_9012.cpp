#include <iostream>
#include <stack>

using namespace std;
stack<int>	s;

void	chk_stack(string str)
{
	int	n;
	n = str.length();
	for (int i = 0; i < n; i ++)
	{
		if (str[i] == '(')
			s.push(str[i]);
		else if (!s.empty() && str[i] == ')')
			s.pop();
		else
		{
			cout << "NO\n";
			return ;
		}
	}
	if (s.empty())
		cout << "YES\n";
	else
		cout << "NO\n";
}

int	main()
{
	ios_base::sync_with_stdio(false);
	int	num;
	string	str;
	cin >> num;
	for (int i = 0; i < num; i ++)
	{
		cin >> str;
		chk_stack(str);
		while (!s.empty())
			s.pop();
	}
}