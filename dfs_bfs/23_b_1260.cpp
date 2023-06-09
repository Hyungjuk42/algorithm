#include <iostream>
#include <queue>

using namespace std;

void	print_arr(int **arr, int n)
{
	for (int i = 0; i <=n; i ++)
	{
		for (int j = 0; j <=n; j ++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

void	dfs(int **arr, int n, int idx, int &res, int n_num)
{
	if (arr[0][idx] == 0)
	{
		arr[0][idx] = 1;
		cout << idx << " ";
		res ++;
	}
	else
		return ;
	for (int i = 1; i <= n; i ++)
	{
		if (arr[idx][i] == 1)
			dfs(arr, n, i, res, n_num);
		if (res == n_num)
			return ;
	}
}

void	bfs(int **arr, int n, int idx, int &res)
{
	queue<int> q;

	while (1)
	{
		if (arr[0][idx])
		{
			arr[0][idx] = 0;
			cout << idx << " ";
			res --;
		}
		if (res == 0)
			return ;
		for (int i = 1; i <= n; i ++)
			if (arr[idx][i] && arr[0][i])
				q.push(i);
		idx = q.front();
		q.pop();
	}
}

int	main(void)
{
	int	n, m, v;
	int s, e;
	int	p_num;
	int n_num;
	int	**arr;

	n_num = 0;
	cin >> n >> m >> v;
	arr = new int*[n + 1];
	for (int i = 0; i <= n; i ++)
		arr[i] = new int[n + 1];
	for (int i = 0; i < m; i ++)
	{
		cin >> s >> e;
		
		arr[s][e] = 1;
		arr[e][s] = 1;
		if (arr[s][0] == 0)
		{
			arr[s][0] = 1;
			n_num ++;
		}
		if (arr[e][0] == 0)
		{
			arr[e][0] = 1;
			n_num ++;
		}
	}
	p_num = 0;
	dfs(arr, n, v, p_num, n_num);
	cout << endl;
	// print_arr(arr, n);
	bfs(arr, n, v, p_num);
}