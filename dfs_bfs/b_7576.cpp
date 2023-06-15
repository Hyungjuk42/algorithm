#include <iostream>
#include <queue>

using namespace std;

typedef struct s_point
{
	int i;
	int j;
} point;

void	print_arr(int **arr, int n, int m)
{
	int	max;

	max = 0;
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			if (arr[i][j] == 1)
			{
				cout << "-1";
				return ;
			}
			else if (arr[i][j] > max)
				max = arr[i][j];
		}
	}
	cout << max - 2;
}

void	print_arr2(int **arr, int n, int m)
{
	int	max;

	max = 0;
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void	chk_side(int **arr, point mid, queue<point> &q)
{
	point	tmp;

	if (arr[mid.i + 1][mid.j] == 1)
	{
		tmp.i = mid.i + 1;
		tmp.j = mid.j;
		arr[mid.i + 1][mid.j] = arr[mid.i][mid.j] + 1;
		q.push(tmp);
	}
	if (arr[mid.i - 1][mid.j] == 1)
	{
		tmp.i = mid.i - 1;
		tmp.j = mid.j;
		arr[mid.i - 1][mid.j] = arr[mid.i][mid.j] + 1;
		q.push(tmp);
	}
	if (arr[mid.i][mid.j + 1] == 1)
	{
		tmp.i = mid.i;
		tmp.j = mid.j + 1;
		arr[mid.i][mid.j + 1] = arr[mid.i][mid.j] + 1;
		q.push(tmp);
	}
	if (arr[mid.i][mid.j - 1] == 1)
	{
		tmp.i = mid.i;
		tmp.j = mid.j - 1;
		arr[mid.i][mid.j - 1] = arr[mid.i][mid.j] + 1;
		q.push(tmp);
	}
}

void	bfs(int **arr, int n, int m)
{
	queue<point>	q;
	point			tmp;

	for(int i = 1; i < n; i ++)
		for(int j = 1; j < m; j ++)
		{
			if (arr[i][j] > 1)
			{
				tmp.i = i;
				tmp.j = j;
				q.push(tmp);
			}
		}
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		chk_side(arr, tmp, q);
	}
}

int main()
{
	int m, n;
	int	**arr;
	cin >> m >> n;

	arr = new int*[n + 2];
	arr[0] = new int[m + 2];
	for (int i = 1; i <= n; i ++)
	{
		arr[i] = new int[m + 2];
		for (int j = 1; j <= m; j ++)
		{
			cin >> arr[i][j];
			arr[i][j] += 1;
		}
	}
	arr[n + 1] = new int[m + 2];
	print_arr2(arr, n + 2, m + 2);
	bfs(arr, n + 2, m + 2);
	print_arr(arr, n + 2, m + 2);
}