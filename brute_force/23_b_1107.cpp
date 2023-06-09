#include <iostream>
#include <math.h>

using namespace std;
int	arr[10];

int	main()
{
	int		n, m;
	int		tmp, res;
	string	tmpstr;

	cin >> n >> m;
	res = abs(n - 100);
	for (int i = 0; i < m; i ++)
	{
		cin >> tmp;
		arr[tmp] = 1;
	}
	tmp = 0;
	for (int i = 0; i <= max(2 * n - tmp, 10); i ++)
	{
		tmpstr = to_string(i);
		for (int j = 0; j < tmpstr.length(); j ++)
		{
			if (arr[tmpstr[j] - '0'])
			{
				tmpstr[0] = 0;
				break ;
			}
		}
		if (!tmpstr[0])
			continue ;
		if (res > tmpstr.length() + abs(n - i))
		{
			tmp = i;
			res = tmpstr.length() + abs(n - i);
			// cout << "num : " << tmp << ", " << res << '\n';
		}
	}
	cout << res;
}