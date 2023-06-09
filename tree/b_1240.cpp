#include <iostream>
#include <list>
#include <queue>
#include <utility>

using namespace std;
list< pair <int, int> >				*lst;
list< pair <int, int> >::iterator	iter;
queue< pair <int, int> >			q;
int									*chk;

int	find_dist(int v, int w, int res)
{
	int				size;
	pair <int, int>	p;
	pair <int, int>	node;

	while (!q.empty())
	{
		// cout << "hello" << endl;
		size = q.size();
		while (size -- > 0)
		{
			p = q.front();
			q.pop();
			iter = lst[p.first].begin();
			if (p.first == w)
			{
				// cout << p.first << " " << w <<  '\n';
				return (p.second);
			}
			while (iter != lst[p.first].end())
			{
				if (chk[(*iter).first] == 0)
				{
					chk[(*iter).first] = 1;
					node.first = (*iter).first;
					node.second = (*iter).second + p.second;
					q.push(node);
					// cout << node.first << " " << node.second << '\n';
				}
				iter ++;
			}
		}
	}
	return (0);
}

void	print_list(int num)
{
	for (int i = 1; i <= num; i ++)
	{
		for (iter = lst[i].begin(); iter != lst[i].end(); iter ++)
			cout << (*iter).first << ", " << (*iter).second << " => ";
		cout << '\n'; 
	}
}

int main()
{
	int				n, m;
	int				v, w, k;
	pair< int, int>	p;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	lst = new list<pair <int, int> >[n + 1];
	chk = new int [n + 1];
	for (int i = 1; i < n; i ++)
	{
		cin >> v >> w >> k;
		p.first = w;
		p.second = k;
		lst[v].push_back(p);
		p.first = v;
		lst[w].push_back(p);
	}
	for (int i = 0; i < m; i ++)
	{
		cin >> v >> w;
		for (int j = 0; j < n + 1; j ++)
			chk[j] = 0;
		chk[v] = 1;
		while(!q.empty())	q.pop();
		p.first = v;
		p.second = 0;
		q.push(p);
		cout << find_dist(v, w, 0) << '\n';
	}
}