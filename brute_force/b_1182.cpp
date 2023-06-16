#include <iostream>

using namespace std;
int main()
{
	int n, m;
	int	res, sum;
	int	*arr;

	cin >> n >> m;
	res = 0;
	arr = new int[n];
	for (int i = 0; i < n; i ++)
		cin >> arr[i];
	for (int bit = 1; bit < (1 << n); bit ++)
	{
		sum = 0;
		for (int i = 0; i < n; i ++)
		{
			if (1 << i & bit)
				sum += arr[i];
		}
		if (sum == m)
			res ++;
	}
	cout << res;
}