/**
 * a[n + 3] = a[n] + a[n + 1] + a[n + 2]
*/

#include <iostream>

using namespace std;

void	split_sum(int *a)
{
	for (int i = 0; i < 9; i ++)
		a[i + 3] = a[i] + a[i + 1] + a[i + 2];
}

int main(void)
{
	int num, ord;
	int *arr;

	cin >> num;
	arr = new int[12];

	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	split_sum(arr);
	for (int i = 0; i < num; i ++)
	{
		cin >> ord;
		cout << arr[ord] << endl;
	}
}