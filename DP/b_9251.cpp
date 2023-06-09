#include <iostream>
#include <math.h>

using namespace std;
int arr[1001][1001];

void	ft_print(int n, int m)
{
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

void	ft_lcs(string s1, string s2, int n, int m)
{
	int	res;

	res = 0;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			if (s1[i - 1] == s2[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
		}

	}
	for (int j = 1; j <= m; j ++)
		if (arr[n][j] >= res)
			res = arr[n][j];
	cout << res;
}

int	main(void)
{
	string	s1, s2;
	int		n, m;

	cin >> s1 >> s2;
	n = s1.length();
	m = s2.length();

	ft_lcs(s1, s2, n, m);
}