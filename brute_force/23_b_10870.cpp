#include <iostream>
#include <stdlib.h>
using namespace std;

int ft_fibo(int ord)
{
	if (ord <= 0)
		return 0;
	else if (ord == 1 || ord == 2)
		return 1;
	return (ft_fibo(ord - 1) + ft_fibo(ord - 2));
}

int	main(void)
{
	int	num;
	int	*arr;

	cin >> num;
	cout << ft_fibo(num);
}