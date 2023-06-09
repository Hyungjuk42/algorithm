#include <stdlib.h>
#include <stdio.h>

void	ft_print_arr(int *arr, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		printf("%d\n", arr[idx]);
		idx ++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_merge_sort(int *arr, int len)
{
	int	*dup_arr;
	int	idx;

	idx = 0;
	if (len <= 1)
		return ;
	ft_merge_sort(arr, len / 2);
	ft_merge_sort(arr + len / 2, len - len / 2);
	dup_arr = (int *) malloc (sizeof(int) * (len));
	while (idx < )
}

int	main(void)
{
	int	idx;
	int	len;
	int	*arr;

	idx = 0;
	scanf("%d", &len);
	arr = (int *) malloc(sizeof(int) * len);
	while (idx < len)
	{
		scanf("%d", arr + idx);
		idx ++;
	}
	ft_merge_sort(arr, len);
	ft_print_arr(arr, len);
}