#include <iostream>
#include <queue>

using namespace std;
queue<int>	q;
int			*arr;
int			sum;
int			t;
int			idx;

int	main()
{
	int	n, w, l;
	int	tmp;

	cin >> n >> w >> l;
	arr = new int[n];
	for (int i = 0; i < n; i ++)
		cin >> arr[i];
	for (t; t < w && idx < n; t ++)
	{
		if (sum + arr[idx] <= l)
		{
			sum += arr[idx];
			q.push(arr[idx]);
			idx ++;
		}
		else
		{
			q.push(0);
		}
	}
	while (idx < n)
	{
		// cout << "time: " << t << " next: " << arr[idx] << "sum: " << sum << endl;
		tmp = q.front();
		q.pop();
		sum -= tmp;
		if (sum + arr[idx] > l)
			q.push(0);
		else
		{
			q.push(arr[idx]);
			sum += arr[idx];
			idx ++;
		}
		t ++;
	}
	t += w;
	cout << t;
}
