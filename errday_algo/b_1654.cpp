#include <iostream>
#include <stdlib.h>

using namespace std;

long long	*arr, n, m;

void	bsearch(long long s, long long e, long long &res)
{
	long long	news;
	long long	tmpres;
	long long	tmpres2;
	int			chk;
	
	chk = 0;
	if (s + 1 >= e)
		chk = 1;
	news = (s + e) / 2;
	tmpres = 0;
	tmpres2 = 0;
	for (int i = 0; i < n; i ++)
	{
		tmpres += arr[i] / news;
		tmpres2 += arr[i] / e;
	}
	if (tmpres2 >= m)
		res = e;
	else if (tmpres >= m)
	{
		res = news;
		if (chk == 0)
			bsearch(news, e, res);
	}
	else
		bsearch(s, news, res);
}

int	main()
{
	long long	avg, res;

	cin >> n >> m;
	arr = (long long *) malloc(sizeof(long long) * n);
	avg = 0;
	for (int i = 0; i < n; i ++)
		cin >> arr[i];
	for (int i = 0; i < n; i ++)
		avg += arr[i];
	avg /= n;
	bsearch(1, avg, res);
	cout << res;
}
