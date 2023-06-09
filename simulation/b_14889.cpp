#include <iostream>
#include <cmath>

using namespace std;
int	**arr;
int	*chk;
int	start, link;
int	s_num, l_num;
int	res;

void	print_arr(int num)
{
	for (int i = 0; i < num; i ++)
	{
		for (int j = 0; j < num; j ++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}

void	back_tracking(int num, int idx)
{
	int	tmp;

	if (idx == num)
	{
		if (res > abs(start - link))
			res = abs(start - link);
		return ;
	}
	tmp = 0;
	if (s_num < num / 2)
	{
		chk[idx] = 1;
		for (int i = 0; i < idx; i ++)
			if (chk[i] == 1)
				tmp += arr[i][idx] + arr[idx][i];
		start += tmp;
		s_num ++;
		back_tracking(num, idx + 1);
		start -= tmp;
		s_num --;
	}
	tmp = 0;
	if (l_num < num / 2)
	{
		chk[idx] = 2;
		for (int i = 0; i < idx; i ++)
			if (chk[i] == 2)
				tmp += arr[i][idx] + arr[idx][i];
		link += tmp;
		l_num ++;
		back_tracking(num, idx + 1);
		link -= tmp;
		l_num --;
	}
}

int main()
{
	int num;

	cin >> num;
	arr = new int*[num];
	chk = new int[num];
	res = 2100000000;
	for (int i = 0; i < num; i ++)
	{
		arr[i] = new int[num];
		for (int j = 0; j < num; j ++)
			cin >> arr[i][j];
	}
	back_tracking(num, 0);
	cout << res;
}