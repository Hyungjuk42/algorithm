#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int num;
	int	arr[3];
	int	prev[3];
	int	res;
	
	cin >> num;
	for (int i = 0; i < 3; i ++)
		cin >> prev[i];
	for (int i = 0; i < num - 1; i ++)
	{
		for (int j = 0; j < 3; j ++)
			cin >> arr[j];
		for (int j = 0; j < 3; j ++)
			arr[j] += min(prev[(j + 1) % 3], prev[(j + 2) % 3]);
		for (int j = 0; j < 3; j ++)
			prev[j] = arr[j];
	}
	res = 1001;
	for (int i = 0; i < num; i ++)
		if (res > prev[i])
			res = prev[i];
	cout << res;
}