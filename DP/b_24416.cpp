#include <iostream>

using namespace std;

int	*arr;

void	fibo_dp(int num)
{
	for(int i = 2; i < num; i ++)
		arr[i] = arr[i - 1] + arr[i - 2];
	cout << arr[num - 1] << " " << num - 3;
}

int	main()
{
	int	num;

	cin >> num;
	arr = new int[num + 1];
	arr[0] = 0;
	arr[1] = 1;
	fibo_dp(num + 1);
}