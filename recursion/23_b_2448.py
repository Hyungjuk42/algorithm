def recur_star(num, idx, arr) :
	if idx == 1 : 
		return
	len = int(num / idx)
	for i in range(int(idx / 2), num, idx) :
		for j in range(num + int(idx / 2) - i - 1, num + i, idx) :
			for k in range(i, i + int(idx / 2)) :
				for l in range(j + 1 - int(idx / 2) + k - i, j + int(idx / 2) - k + i) :
					arr[k][l] = ' '
	recur_star(num, int(idx / 2), arr)

num = int(input())

arr = []
for i in range(0, num) :
	arr.append(list(' ' * (num - i - 1) + '*' * (1 + 2 * i) + ' ' * (num - i - 1)))

recur_star(num, num, arr)

for j in range(0, num) :
	print(''.join(arr[j]))
