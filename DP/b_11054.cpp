#include <iostream>

using namespace std;

void	printarr(int *arr, int num)
{
	for (int i = 0; i < num; i ++)
		cout << arr[i] << " ";
}

void	makearr(int *arr, int *res1, int *res2, int num, int &r)
{
	int tmp;

	r = 2;
	for (int i = 1; i < num; i ++)
	{
		tmp = 0;
		for (int j = 0; j < i; j ++)
		{
			if (arr[j] < arr[i] && res1[j] > tmp)
				tmp = res1[j];
		}
		res1[i] = tmp + 1;
	}
	for (int i = num - 1; i >= 0; i --)
	{
		tmp = 0;
		for (int j = i; j < num; j ++)
		{
			if (arr[j] < arr[i] && res2[j] > tmp)
				tmp = res2[j];
		}
		res2[i] = tmp + 1;
		res1[i] += res2[i];
		if (res1[i] > r)
			r = res1[i];
	}
	r --;
}

int main(void)
{
	int	num;
	int	*arr, *res1, *res2;
	int r;

	cin >> num;
	arr = new int[num];
	res1 = new int[num];
	res2 = new int[num];

	for(int i = 0; i < num; i ++)
		cin >> arr[i];
	res1[0] = 1;
	res2[num - 1] = 1;
	makearr(arr, res1, res2, num, r);
	cout << r;
}