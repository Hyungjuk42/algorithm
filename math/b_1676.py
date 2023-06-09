def ft_cntfactor(num, factor) :
	tmp = 0
	while (num % factor == 0) :
		num /= factor
		tmp += 1
	return (tmp)
	
def ft_rec(max, num, chknum) :
	if max < num * chknum :
		return
	if chknum == 2 :
		arr_2[num * chknum] = arr_2[num] + 1
	if chknum == 5 :
		arr_5[num * chknum] = arr_5[num] + 1
	ft_rec(max, num * 2, 2)
	ft_rec(max, num * 5, 5)

if __name__ == '__main__' :
	n = int(input())

	arr_2 = [0 for idx in range(n + 1)]
	arr_5 = [0 for idx in range(n + 1)]
	for i in range(1, n + 1) :
		if arr_2[i] == 0 and arr_5[i] == 0 :
			tmp2 = ft_cntfactor(i, 2)
			tmp5 = ft_cntfactor(i, 5)
		ft_rec(n, i, 2)
		ft_rec(n, i, 5)
	tmp2 = 0
	tmp5 = 0
	for i in range(1, n + 1) :
		tmp2 += arr_2[i]
		tmp5 += arr_5[i]
	print(min(tmp2, tmp5))