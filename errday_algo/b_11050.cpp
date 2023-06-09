#include <iostream>

using namespace std;

int	main()
{
	long long	n, m;
	long long	other;
	long long	res;

	cin >> n >> m;
	if (n - m > m)
		m = n - m;
	other = 1;
	res = n;
	for (int i = 2; i <= n - m; i ++)
		other *= i;
	for (int i = n - 1; i > m; i --)
		res *= i;
	cout << res / other;
}
