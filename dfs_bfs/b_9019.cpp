#include <iostream>
#include <queue>

using namespace std;
queue <pair <short, string> >	q;
pair <short, string>			p;
bool	chk[10001];

int	rotate_true(int e)
{
	short	s;
	string	str;

	s = p.first;
	str = "";
	for (int i = 0; i < 4; i ++)
	{
		s = p.first / 1000 + p.first % 1000 * 10;
		str += 'L';
		if (s == e)
		{
			if (i > 2)
				p.second += 'R';
			else
				p.second += str;
			return (1);
		}
	}
	return (0);
}

void	bfs(short e)
{
	string	str;
	pair<short, string> curp;
	int		i;

	while(1)
	{
		p = q.front();
		q.pop();
		str = p.second;
		if (p.first == e)
			break ;
		i = -1;
		do
		{
			i ++;
			curp = p;
			switch (i)
			{
				case 0:
					curp.first *= 2;
					if (curp.first > 9999)
						curp.first -= 10000;
					curp.second += 'D';
					break ;
				case 1:
					if (curp.first == 0)
						curp.first = 9999;
					else
						curp.first -= 1;
					curp.second += 'S';
					break ;
				case 2:
					curp.first = p.first / 1000 + (p.first % 1000) * 10;
					curp.second += 'L';
					break ;
				case 3:
					curp.first = p.first / 10 + (p.first % 10) * 1000;
					curp.second += 'R';
					break ;
				default :
					break ;
			}
			if (chk[curp.first] == 0)
			{
				chk[curp.first] = 1;
				q.push(curp);
			}
		} while (p.first != e && i < 4);
		if (p.first == e)
			break ;
	}
}

int	main()
{
	int		num;
	short	e;

	cin >> num;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < num; i ++)
	{
		cin >> p.first >> e;
		p.second = "";
		q.push(p);
		bfs(e);
		cout << p.second << endl;
		while (!q.empty())
			q.pop();
		for (int i = 0; i < 10001; i ++)
			chk[i] = 0;
	}
}