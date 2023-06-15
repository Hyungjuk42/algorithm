#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
queue< pair <int, int> >	q;

int	print_q()
{
	int				n, m;
	int				max;
	int				res;
	int				*arr;
	pair<int, int>	p;

	p.second = 0;
	res = 0;
	cin >> n >> m;
	arr = new int[n];
	for (int i = 0; i < n; i ++) 
	{
		cin >> arr[i];
		p.first = arr[i];
		if (i == m)
			p.second = 1;
		q.push(p);
		if (i == m)
			p.second = 0;
	}
	sort(arr, arr + n, greater<int>());
	for (int i = 0; i < n; i ++)
	{
		while (arr[i] != q.front().first)
		{
			q.push(q.front());
			q.pop();
		}
		p = q.front();
		q.pop();
		res ++;
		if (p.second == 1)
			return (res);
	}
	return (res);
}

int	main()
{
	int	num;

	cin >> num;
	for (int i = 0; i < num; i ++)
	{
		cout << print_q() << '\n';
		while (!q.empty())
			q.pop();
	}
}