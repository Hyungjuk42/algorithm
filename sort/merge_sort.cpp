#include <iostream>
#include <vector>

using namespace std;
using List = vector<int>;

void makeArr(List &lst, int num)
{
	for (int i = 0; i < num; i ++)
		cin >> lst[i];
}

void print_arr(List lst, int num)
{
	for (int i = 0; i < num; i ++)
		cout << lst[i] << '\n';
}

void merge_sort(List &lst, int s, int e)
{
	List	buf(e - s);
	int		m = (s + e) / 2;

	if (s == m)
		return ;
	merge_sort(lst, s, m);
	merge_sort(lst, m, e);
	for (int i = 0; i < m - s; i ++)
		buf[i] = lst[i + s];
	for (int i = 0; i < e - m; i ++)
		buf[e - s - i - 1] = lst[m + i];
	int	bufs = 0;
	int	bufe = e - s - 1;
	for (int i = s; i < e; i ++)
	{
		if (buf[bufs] <= buf[bufe])
			lst[i] = buf[bufs ++];
		else
			lst[i] = buf[bufe --];
	}
}

int main()
{
	int num;
	cin >> num;
	List lst(num);
	makeArr(lst, num);
	merge_sort(lst, 0, num);
	print_arr(lst, num);
}