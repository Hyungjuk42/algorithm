#include <iostream>
#include <stdlib.h>

using namespace std;

int main (void)
{
	int		row;
	int		col;
	int		res;
	int		min;
	char	**arr;

	cin >> row >> col;
	min = row * col;
	arr = new char *[row];
	for (int i = 0; i < row; i ++)
	{
		arr[i] = new char [col];
		for (int j = 0; j < col; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i <= row - 8; i ++)
	{
		for (int j = 0; j <= col - 8; j++)
		{
			res = 0;
			for (int y = 0; y < 8; y++)
			{
				for (int x = 0; x < 8; x++)
				{
					if ((x + y) % 2 == 1 && arr[i + y][j + x] == arr[i][j])
						res ++;
					else if ((x + y) % 2 == 0 && arr[i + y][j + x] != arr[i][j])
						res ++;
				}
			}
			if (res > 64 - res)
				res = 64 - res;
			if (min > res)
				min = res;
		}
	}
	cout << min << endl;
	
	return (0);
}
