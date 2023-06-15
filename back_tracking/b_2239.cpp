#include <iostream>

using namespace std;

void	print_num(int arr[][9])
{
	for(int i = 0; i < 9; i ++)
	{
		for(int j = 0; j < 9; j ++)
			cout << arr[i][j];
		cout << endl;
	}
}

int	chk_possible(int arr[][9], int i, int j)
{
	int num;

	num = arr[i][j];
	for (int t = 0; t < 9; t ++)
		if (arr[i][t] == num && t != j)
			return (0);
	for (int t = 0; t < 9; t ++)
		if (arr[t][j] == num && t != i)
			return (0);
	for (int t1 = 3 * (i / 3); t1 < 3 * (i / 3 + 1); t1 ++)
		for (int t2 = 3 * (j / 3); t2 < 3 * (j / 3 + 1); t2 ++)
			if (arr[t1][t2] == num && (t1 != i || t2 != j))
				return (0);
	return (1);
}

int	solve_sudoku(int arr[][9], int i, int j)
{
	if (i == 9)
	{
		print_num(arr);
		return (1);
	}

	int	*num;
	num = &arr[i][j];
	if(*num > 0)
		return (solve_sudoku(arr, i + (j + 1) / 9, (j + 1) % 9));
	else if(*num == 0)
	{
		(*num) = (*num) + 1;
		for(*num; *num <= 9; (*num) ++)
		{
			if(chk_possible(arr, i, j) && solve_sudoku(arr, i + (j + 1) / 9, (j + 1) % 9))
				return (1);
		}
		(*num) = 0;
	}
	return (0);
}

int main(void)
{
	int arr[9][9];
	char c;

	for(int i = 0; i < 9; i ++)
		for(int j = 0; j < 9; j ++)
		{
			cin >> c;
			arr[i][j] = c - '0';
		}
	
	solve_sudoku(arr, 0, 0);
}