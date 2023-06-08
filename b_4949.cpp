#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<int>	s;

void	chk_str(string str)
{
	int	len;

	len = str.length();
	for (int i = 0; i < len; i ++)
	{
		if (str[i] == '(' || str[i] == '[')
			s.push(str[i]);
		if (str[i] == ')' || str[i] == ']')
		{
			if (!s.empty() && str[i] - s.top() < 3)
				s.pop();
			else
			{
				cout << "no\n";
				while (!s.empty())
					s.pop();
				return ;
			}
		}
	}
	if (s.empty())
		cout << "yes\n";
	else
		cout << "no\n";
	while (!s.empty())
		s.pop();
}

int	main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string	str;
	while (1)
	{
		cin.clear();
		getline(cin, str);
		if (str.length() == 1 && str[0] == '.')
			break ;
		chk_str(str);
	}
}