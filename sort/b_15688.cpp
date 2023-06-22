// unordered set + merge
#include <iostream>
#include <vector>
#include <map>

using namespace std;
using List = vector<int>;
using Map = map<int, int>;

Map dict;

int makeArr(List &lst, int num)
{
	int	val;
	int	chk;

	chk = 0;
	for (int i = 0; i < num; i ++)
	{
		cin >> val;
		dict[val] ++;
		if (!lst.empty() && lst.back() > val)
			chk = 1;
		if (dict[val] == 1)
		{
			lst.push_back(val);
		}
	}
	return (chk);
}

void print_arr(List lst, int num)
{
	for (int i = 0; i < num; i ++)
		for (int j = 0; j < dict[lst[i]]; j ++)
			cout << lst[i] << ' ';
	cout << '\n';
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
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int num;
	cin >> num;
	List lst;
	if (makeArr(lst, num))
		merge_sort(lst, 0, lst.size());
	print_arr(lst, lst.size());
}