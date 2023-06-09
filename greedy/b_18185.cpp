#include <iostream>

using namespace std;

int	main(void)
{
	int	n, sum;
	int	*arr;

	sum = 0;
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i ++)
		cin >> arr[i];
	for (int i = 0; i < n - 2; i ++)
		while (arr[i] && arr[i + 1] && arr[i + 2])
		{
			if (arr[i + 1] > arr[i + 2])
			{
				arr[i] --;
				arr[i + 1] --;
				sum += 5;
			}
			else
			{
				arr[i] --;
				arr[i + 1] --;
				arr[i + 2] --;
				sum += 7;
			}
		}
	for (int i = 0; i < n - 1; i ++)
		while (arr[i] && arr[i + 1])
		{
			arr[i] --;
			arr[i + 1] --;
			sum += 5;
		}
	for (int i = 0; i < n; i ++)
		while (arr[i])
		{
			arr[i] --;
			sum += 3;
		}
	
	cout << sum;
}