#include <iostream>

using namespace std;
int	*arr;

void	chk_boonyeo()
{
	int	k, n;

	cin >> k >> n;
	arr = new int[n];
	for (int i = 0; i < n; i ++)
		arr[i] = i + 1;
	for (int i = 0; i < k; i ++)
	{
		for (int j = 1; j < n; j ++)
		{
			arr[j] += arr[j - 1];
		}
	}
	cout << arr[n - 1];
	delete(arr);	
}

int	main()
{
	int	num;

	cin >> num;
	for (int i = 0; i < num; i ++)
		chk_boonyeo();
}