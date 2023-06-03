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

void 	print_arr(int num)
{
	for (int i = 0; i < num; i ++)
		cout << arr[i] << '\n';
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

int	main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int	num;
	cin >> num;
	arr = new int [num];
	for (int i = 0; i < num; i ++)
		cin >> arr[i];
	quick_sort(0, num - 1);
	print_arr(num);
}
