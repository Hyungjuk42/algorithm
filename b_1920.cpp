#include <iostream>

using namespace std;
int	*arr;

void	swap(int a, int b)
{
	int	tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void	quick_sort(int s, int e)
{
	int	l, r;
	int	tmp;

	l = s + 1;
	r = e;
	while (l < r)
	{
		while (arr[l] <= arr[s] && l < e)
			l ++;
		while (arr[r] > arr[s] && r > s)
			r --;
		if (l < r)
			swap(l, r);
		else
		{
			swap(s, r);
			quick_sort(s, r - 1);
			quick_sort(r + 1, e);
		}
	}
}

int	binary_search(int s, int e, int find)
{
	int m;

	m = (s + e) / 2;
	if (arr[m] == find)
		return (1);
	if (s + 1 > e)
		return (0);
	else if (find > arr[m])
		return (binary_search(m + 1, e, find));
	else
		return (binary_search(s, m - 1, find));
}

int	main()
{
	int	n, m, find;

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i ++)
		cin >> arr[i];
	quick_sort(0, n - 1);
	cin >> m;
	for (int i = 0; i < m; i ++)
	{
		cin >> find;
		if (find == arr[n - 1])
			cout << "1\n";
		else
			cout << binary_search(0, n - 1, find) << '\n';
	}
}
