#include <iostream>
#include <algorithm>

using namespace std;
long long	arr[1000001];
long long	sum[1000001];
int	res;
int n, m;

void	chk_res(int s, int e)
{
	int	p;
	int rev;
	int	tmpres;
	long long tmp;

	tmpres = res + 1;
	rev = n + 1 - tmpres;
	res = s;
	p = (s + e) / 2;
	while (1)
	{
		tmp = sum[tmpres] + rev * (arr[tmpres] - p);
		// cout << "s: " << s << " p: " << p << " tmp: " << tmp << " e:" << e << '\n';
		if (m <= tmp)
		{
			res = p;
			if (p == s)
				break ;
			s = p + 1;
		}
		else if (p == s)
			break ;
		else
			e = p;
		p = (s + e) / 2;
	}
	cout << res;
}

void bs(int s, int e)
{
	int	p;

	p = (s + e) / 2;
	if (s == p)
	{
		if (sum[p] >= m)
			res = p;
		if (sum[res] == m)
			cout << arr[res];
		else
			chk_res(arr[res], arr[res + 1]);
		return ;
	}
	if (sum[p] > m)
	{
		res = p;
		bs(p, e);
	}
	else if (sum[p] < m)
		bs(s, p);
	else
		cout << arr[p];
}

int main()
{

	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> arr[i];
	sort(arr, arr + n + 1);
	sum[n] = 0;
	int j = 0;
	for (int i = n - 1; i > 0; i --)
	{
		j ++;
		sum[i] = (arr[i + 1] - arr[i]) * j + sum[i + 1];
	}
	bs(1, n + 1);
}