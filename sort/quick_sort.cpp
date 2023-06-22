#include <iostream>
#include <vector>

using namespace std;
using List = vector <int>;

int		num;
List	arr;

void makeArr(int num)
{
	int	val;

	for (int i = 0; i < num; i ++)
	{
		cin >> val;
		arr.push_back(val);
	}
}

void print_arr(int num)
{
	for (int i = 0; i < num; i ++)
		cout << arr[i] << ' ';
	cout << '\n';
}

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
	cin >> num;
	makeArr(num);
	quick_sort(0, num - 1);
	print_arr(num);
}