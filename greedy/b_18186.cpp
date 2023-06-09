#include <iostream>

using namespace std;

int	main(void)
{
	int	n, b, c, sum;
	int	*arr;

	sum = 0;
	cin >> n >> b >> c;
	if (b < c)
		c = b;
	arr = new int[n];
	for (int i = 0; i < n; i ++)
		cin >> arr[i];
	for (int i = 0; i < n - 2; i ++)
		while (arr[i] && arr[i + 1] && arr[i + 2])
		{
			if (arr[i + 1] <= arr[i + 2])
			{
				arr[i + 2] --;
				arr[i] --;
				arr[i + 1] --;
				sum ++;
			}
			else
			{
				arr[i] --;
				arr[i + 1] --;
				sum ++;
			}
		}
	for (int i = 0; i < n - 1; i ++)
		while (arr[i] && arr[i + 1])
		{
			arr[i] --;
			arr[i + 1] --;
			sum += b + c;
		}
	for (int i = 0; i < n; i ++)
		while (arr[i])
		{
			arr[i] --;
			sum += b;
		}
	
	cout << sum;
}