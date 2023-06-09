#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
deque<int>	deq;

int	pop_first()
{
	int	tmp;

	tmp = deq.front();
	deq.pop_front();
	return (tmp);
}

int	left_move(int num)
{
	int	tmp;
	int	res;

	res = 0;
	while (deq.front() != num)
	{
		tmp = pop_first();
		deq.push_back(tmp);
		res += 1;
	}
	return (res);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int	n, m;
	int	elem, res;
	int	tmp;

	cin >> n >> m;
	res = 0;
	for (int i = 1; i <= n; i ++)
		deq.push_back(i);
	for (int i = 0; i < m; i ++)
	{
		cin >> elem;
		tmp = left_move(elem);
		res += min(tmp, (int)deq.size() - tmp);
		// cout << tmp << " " << (int)deq.size() - tmp << "\t";
		pop_first();
	}
	cout << res;
}