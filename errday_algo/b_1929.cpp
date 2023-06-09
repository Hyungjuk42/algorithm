#include <iostream>
#include <cmath>

using namespace std;
int	*arr;

void	find_prime(int num)
{
	int	max;

	max = pow(num, 0.5);
	for (int i = 2; i < max; i ++)
	{
		if (arr[i] == 0)
		{
			for (int j = 2; i * j <= num; j ++)
				arr[i * j] = 1;
		}
	}
}

void	print_prime(int s, int e)
{
	for (int i = s; i < e; i ++)
		if (arr[i] == 0)
			cout << i << '\n';
}

int	main()
{
	int	s, e;
	cin >> s >> e;
	arr = new int [e + 1]();
	arr[1] = 1;
	find_prime(e);
	print_prime(s, e);
}