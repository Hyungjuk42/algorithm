#include <iostream>
#include <queue>

using namespace std;

int	a[100001];

int	make_one_dp(int cur, int tmp, int num)
{
	tmp ++;
	if (cur > num)
		return 1;
	cout << cur << " " << tmp << endl;
	a[cur] = tmp;
	if (cur == num)
	{
		cout << "tmp ; " << tmp << endl;
		return 0;
	}
	if (make_one_dp(cur * 3, tmp, num))
		if (make_one_dp(cur * 2, tmp, num))
			return (make_one_dp(cur + 1, tmp, num));
	return 0;
}

int main()
{
	int num;
	cin >> num;
	make_one_dp(1, 0, num);
}