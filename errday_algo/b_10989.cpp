#include <iostream>

using namespace std;
int	arr[10001];

int	main()
{
	int	num, max;
	int	n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> num;
	max = 1;
	for (int i = 0; i < num; i ++)
	{
		cin >> n;
		if (max < n)
			max = n;
		arr[n] += 1;
	}
	for (int i = 0; i < max + 1; i ++)
		while (arr[i] -- > 0)
			cout << i << '\n';
}
