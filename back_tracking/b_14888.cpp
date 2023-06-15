#include <iostream>
#include <climits>
using namespace std;

int num;
int r_min = INT_MAX;
int r_max = INT_MIN;

void	cmp_res(int *a_num, int *a_opnum)
{
	int	res;

	res = a_num[0];
	for(int i = 0; i < num - 1; i ++)
	{
		switch(a_opnum[i])
		{
			case 0:
				res += a_num[i + 1];
				break ;
			case 1:
				res -= a_num[i + 1];
				break ;
			case 2:
				res *= a_num[i + 1];
				break ;
			case 3:
				res /= a_num[i + 1];
				break ;
			default :
				break ;
		}
	}
	if (res > r_max)
		r_max = res;
	if (res < r_min)
		r_min = res;
}

void	recur_op(int *a_num, int *a_op, int *a_opnum, int n)
{
	if (n == 0)
	{
		cmp_res(a_num, a_opnum);
		return ;
	}
	for(int i = 0; i < 4; i ++)
	{
		if (a_op[i])
		{
			a_opnum[num - n - 1] = i;
			a_op[i] --;
			recur_op(a_num, a_op, a_opnum, n - 1);
			a_op[i] ++;
			a_opnum[num - n - 1] = 0;
		}
	}
	
}

int	main(void)
{
	int	*a_num;
	int	*a_op;
	int	*a_opnum;

	cin >> num; 
	a_num = new int[num];
	a_opnum = new int[num - 1];

	for(int i = 0; i < num; i ++)
	{
		cin >> a_num[i];
	}
	a_op = new int[4];
	for(int i = 0; i < 4; i ++)
	{
		cin >> a_op[i];
	}
	recur_op(a_num, a_op, a_opnum, num - 1);
	cout << r_max << endl;
	cout << r_min << endl;
}