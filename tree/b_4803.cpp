#include <iostream>
#include <list>
#include <queue>
#include <utility>

using namespace std;

list <int>	*lst;
list <int>::iterator iter;
queue < pair <int, int> >	q;
pair <int, int>	p;
int			*chk;

int	bfs_tree()
{
	int				size;
	pair <int, int> node;

	while(!q.empty())
	{
		size = q.size();
		while (size -- > 0)
		{
			p = q.front();
			q.pop();
			node.second = p.first;
			for (iter = lst[p.first].begin(); iter != lst[p.first].end(); iter ++)
			{
				if (chk[*iter] == 1 && *iter != p.second)
					return (-1);
				else if (chk[*iter] == 0)
				{
					chk[*iter] = 1;
					node.first = *iter;
					q.push(node);
				}
			}
		}
	}
	return (0);
}

int main(void)
{
	int	ord, res;
	int n, m;
	int	v, w;

	ord = 0;
	while (1)
	{
		ord ++;
		res = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break ;
		lst = new list <int> [n + 1]();
		chk = new int [n + 1]();
		for (int i = 0; i < m; i ++)
		{
			cin >> v >> w;
			lst[v].push_back(w);
			lst[w].push_back(v);
		}
		for (int i = 1; i <= n; i ++)
		{
			if (chk[i] == 0)
			{
				res += 1;
				q = queue < pair <int, int> >();
				p.first = i;
				p.second = i;
				q.push(p);
				chk[i] = 1;
				res += bfs_tree();
			}
		}
		cout << "Case " << ord << ": ";
		if (res == 0)
			cout << "No trees." << '\n';
		else if (res == 1)
			cout << "There is one tree." << '\n';
		else
			cout << "A forest of " << res <<" trees." << '\n';

	}
}