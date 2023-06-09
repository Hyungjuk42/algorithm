#include <iostream>

using namespace std;

int	**make_map(int m, int n, int t)
{
	int	x, y;
	int	**arr;

	arr = new int*[n];
	for (int i = 0; i < n; i ++)
		arr[i] = new int[m];
	for (int i = 0; i < t; i ++)
	{
		cin >> x >> y;
		arr[y][x] = 1;
	}
	return (arr);
}

void	dfs_worm(int **arr, int m, int n, int j, int k)
{
	if (k < 0 || k >= m || j < 0 || j >= n || arr[j][k] == 0)
		return ;
	arr[j][k] = 0;
	dfs_worm(arr, m, n, j + 1, k);
	dfs_worm(arr, m, n, j - 1, k);
	dfs_worm(arr, m, n, j, k + 1);
	dfs_worm(arr, m, n, j, k - 1);
}

int	main()
{
	int	test_num;
	int	m, n, k;
	int	res;
	int	**arr;
	
	cin >> test_num;
	for (int i = 0; i < test_num; i ++)
	{
		res = 0;
		cin >> m >> n >> k;
		arr = make_map(m, n, k);
		for (int j = 0; j < n; j ++)
			for (int k = 0; k < m; k ++)
				if (arr[j][k] == 1)
				{
					res ++;
					dfs_worm(arr, m, n, j, k);
				}
		cout << res << endl;
	}
}