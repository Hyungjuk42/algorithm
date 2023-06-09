#include <iostream>

using namespace std;

void	zeroone(int *arr, int num)
{
	for(int i = 3; i <=num; i ++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
}

int main(void)
{
	int num;
	int	*arr;

	cin >> num;
	if (num <= 2)
		cout << num;
	else
	{
		arr = new int[num + 1];
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 2;

		zeroone(arr, num);
		cout << arr[num];
	}

	return (0);
}