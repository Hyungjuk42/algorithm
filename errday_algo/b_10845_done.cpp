#include <iostream>
#include <deque>

using namespace std;

deque<int>	deq;

void ft_chk_cmd(string cmd)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int	tmp;

	if (cmd == "push")
	{
		cin >> tmp;
		deq.push_back(tmp);
	}
	else if (cmd == "size")
	{
		cout << deq.size() << "\n";
	}
	else if (cmd == "empty")
	{
		cout << deq.empty() << "\n";
	}
	else if (deq.empty())
		cout << "-1\n";
	else
	{
		if (cmd == "pop")
		{
			cout << deq.front() << "\n";
			deq.pop_front();
		}
		else if (cmd == "back")
		{
			cout << deq.back() << "\n";
		}
		else if (cmd == "front")
		{
			cout << deq.front() << "\n";
		}
	}
}
 
int	main(void)
{
	int		n;
	string	cmd;

	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin >> cmd;
		ft_chk_cmd(cmd);
	}
}
