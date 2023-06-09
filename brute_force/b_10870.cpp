#include <iostream>
#include <stdlib.h>
using namespace std;

int ft_fibo(int ord, int *arr)
{
	if (ord == 0)
		arr[ord] = 0;
	else if (ord == 1 || ord == 2)
		arr[ord] = 1;
	else
	{
		if (!arr[ord - 1])
			arr[ord - 1] = ft_fibo(ord - 2, arr) + ft_fibo(ord - 3, arr);
		if (!arr[ord - 2])
			arr[ord - 2] = ft_fibo(ord - 3, arr) + ft_fibo(ord - 4, arr);
		arr[ord] = arr[ord - 1] + arr[ord - 2];
	}
	return (arr[ord]);
}

int	main(void)
{
	int	num;
	int	*arr;

	cin >> num;
	arr = new int[num];
	cout << ft_fibo(num, arr);
}