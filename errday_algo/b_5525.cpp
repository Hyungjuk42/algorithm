#include <iostream>

using namespace std;
string	str;

int	chk_str(int idx, int n)
{
	for (int i = 0; i < 2 * n + 1; i ++)
	{
		if (i % 2 == 0 && str[idx - i] != 'I')
			return (0);
		if (i % 2 == 1 && str[idx - i] != 'O')
			return (0);
	}
	return (1);
}

int main()
{
	int	n, m;
	int	boost_mode;
	int	res;

	cin >> n >> m;
	cin >> str;
	boost_mode = 0;
	res = 0;

	for (int i = 2 * n - 2; i < m; i ++)
	{
		if (chk_str(i, n) == 1)
		{
			i += 2;
			res ++;
			while (i < m)
			{
				if (str[i - 1] != 'O' || str[i] != 'I')
				{
					i += 2 * n - 2;
					break ;
				}
				else
				{
					i += 2;
					res ++;
				}
			}
		}
	}
	cout << res;
}