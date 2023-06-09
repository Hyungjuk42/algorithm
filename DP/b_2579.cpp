/**
 * res[n][0] = arr[n] + res[n - 1][1]
 * res[n][1] = arr[n] + max(res[n - 2][0], res[n - 2][1])
 * 
 * using stairs not to step in
 * res[n] = min(res[n - 2], res[n - 3]) + arr[n]
*/

#include <iostream>
#include <math.h>

using namespace std;

void	stairs(int *res, int *arr, int num)
{
	res[0] = arr[0];
	res[1] = arr[1];
	res[2] = arr[2];
	for(int i = 3; i < num; i ++)
		res[i] = min(res[i - 3], res[i - 2]) + arr[i];
}

int main(void)
{
	int	num, *arr, *res;
	int	r;

	r = 0;
	cin >> num;
	arr = new int[num];
	res = new int[num];
	for(int i = 0; i < num; i ++)
	{
		cin >> arr[i];
		r += arr[i];
	}
	stairs(res, arr, num);
	cout << r - min(res[num - 2], res[num - 3]);
}