#include <iostream>

using namespace std;

void	printarr(int *arr, int num)
{
	for (int i = 0; i < num; i ++)
		cout << arr[i] << " ";
	cout << "\n";
}

void	makearr(int *arr, int *res, int num, int &r)
{
	int tmp;

	r = 1;
	for (int i = 1; i < num; i ++)
	{
		tmp = 0;
		for (int j = 0; j < i; j ++)
		{
			if (arr[j] < arr[i] && res[j] > tmp)
				tmp = res[j];
		}
		res[i] = tmp + 1;
		if (r < res[i])
			r = res[i];
	}
}

int main(void)
{
	int	num;
	int	*arr, *res;
	int r;

	cin >> num;
	arr = new int[num];
	res = new int[num];

	for(int i = 0; i < num; i ++)
		cin >> arr[i];
	res[0] = 1;
	makearr(arr, res, num, r);
	cout << num;
	printarr(arr, num);
	printarr(res, num);
	cout << r;
}