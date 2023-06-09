#include <iostream>
#include <list>
#include <queue>

using namespace std;
list<int>			*lst;
list<int>::iterator iter;
queue<int>			q;
int					*res;

void	find_parents()
{
	int	num;

	while (!q.empty())
	{
		num = q.front();
		q.pop();
		iter = lst[num].begin();
		while (iter != lst[num].end())
		{
			if (res[*iter] == 0)
			{
				res[*iter] = num;
				q.push(*iter);
			}
			iter ++;
		}
	}
}

void	print_arr(int num)
{
	for (int i = 1; i < num; i ++)
	{
		cout << res[i + 1] << '\n';
	}
}

int main()
{
	int			num;
	int			n, m;

	cin >> num;
	lst = new list<int> [num + 1];
	res = new int [num + 1];
	for (int i = 2; i <= num; i ++)
	{
		cin >> n >> m;
		lst[n].push_back(m);
		lst[m].push_back(n);
	}
	res[1] = 1;
	q.push(1);
	find_parents();
	print_arr(num);
}