/**
 * 
*/
#include <iostream>
#include <math.h>

using namespace std;
int arr[101][100001];

void	print_arr(int n, int k)
{
	for (int i = 0; i <= n; i ++)
	{
		for (int j = 0; j <= k; j ++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}

int	main(void)
{
	int	n, k;
	int	w, v;

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> w >> v;
		for (int j = 0; j <= k; j ++)
		{
			arr[i][j] = arr[i - 1][j];
			if (j - w >= 0)
				arr[i][j] = max(arr[i][j], arr[i - 1][j - w] + v);
		}
	}
	//print_arr(n, k);
	cout << arr[n][k];
}