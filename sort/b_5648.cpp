#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string		str;
long long	*arr;
int			num;

void print_arr(int num)
{
	for (int i = 0; i < num; i ++)
		cout << arr[i] << '\n';
	// cout << '\n';
}

void	swap(int a, int b)
{
	long long	tmp;

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
	if (s + 1 == e)
	{
		if (arr[s] > arr[e])
			swap(s, e);
		return ;
	}
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

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;
	arr = new long long [num];
	for (int i = 0; i < num; i ++)
	{
		cin >> str;
		reverse(str.begin(), str.end());
		arr[i] = stoll(str);
	}
	quick_sort(0, num - 1);
	print_arr(num);
}