#include <iostream>
#include <deque>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

deque<int>	deq;
int			rev;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int	n, m, i;
	int	cursor;
	string	cmd, lst;
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin.ignore();
		cin >> cmd >> m >> lst;
		cursor = 1;
		deq.clear();
		rev = -1;
		for (int j = 0; j < m; j ++)
		{
			deq.push_back(atoi(&lst[cursor]));
			while (lst[cursor] != ',' and lst[cursor] != ']')
				cursor ++;
			if (lst[cursor] == ']')
				break ;
			cursor ++;
		}
		for (int j = 0; j < cmd.length(); j ++)
		{
			if (cmd[j] == 'D')
			{
				if (deq.empty())
				{
					deq.push_back(-1);
					break ;
				}
				else if (rev == 1)
					deq.pop_back();
				else if (rev == -1)
					deq.pop_front();
			}
			else if (cmd[j] == 'R')
				rev *= -1;
		}
		if (!deq.empty() && deq.front() == -1)
		{
			deq.pop_front();
			cout << "error\n";
		}
		else
		{
			cout << "[";
			while (deq.size() > 1)
			{
				if (rev == -1)
				{
					cout << deq.front() << ",";
					deq.pop_front();
				}
				else if (rev == 1)
				{
					cout << deq.back() << ",";
					deq.pop_back();
				}
			}
			if (deq.size() == 1)
				cout << deq.front();
			cout << "]\n";
		}
	}
}