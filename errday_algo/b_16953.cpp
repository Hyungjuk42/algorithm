#include <iostream>

using namespace std;

int main()
{
	int a, b;
	int cnt;

	cin >> a >> b;
	cnt = 0;
	while (a < b)
	{
		if (b % 2 == 0)
			b /= 2;
		else if (b % 10 == 1)
			b /= 10;
		else
			break ;
		cnt ++;
	}
	if (a == b)
		cout << cnt + 1;
	else
		cout << "-1";

}