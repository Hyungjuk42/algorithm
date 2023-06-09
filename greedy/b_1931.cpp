#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef struct s_point
{
	int	s;
	int	e;
}	point;

int	ft_cmp(point a, point b)
{
	if (a.e == b.e)
		return (a.s < b.s);
	return (a.e < b.e);
}

void	ft_printarr(vector<point> arr, int n)
{
	for(int i = 0; i < n; i ++)
	{
		cout << arr[i].s << " " << arr[i].e << ",\t";
	}
}

int	main()
{
	int				n;
	int				tmp, res;
	vector<point>	arr;

	cin >> n;
	arr = vector<point>(n);
	for (int i = 0; i < n; i ++)
	{
		cin >> arr[i].s >> arr[i].e;
	}
	sort(&arr[0], &arr[n], ft_cmp);
	
	tmp = arr[0].e;
	res = 1;
	for (int i = 1; i < n; i ++)
	{
		if (tmp <= arr[i].s)
		{
			tmp = arr[i].e;
			res ++;
		}
	}
	cout << res;
}