import sys
import time

n, m = map(int, sys.stdin.readline().strip().split())

if n >= m :
	print(n - m)
	for i in range(n, m - 1, -1) :
		print(i, end = ' ')
else :
	q = []
	arr = [-1 for _ in range(0, 2 * m)]
	arr[n] = 0
	tmp = 0
	prev = n
	while arr[m] == -1 :
		if prev - 1 >= 0 and arr[prev - 1] == -1 :
			arr[prev - 1] = arr[prev] + 1
			q.append(prev - 1)
		if arr[prev + 1] == -1 :
			arr[prev + 1] = arr[prev] + 1
			q.append(prev + 1)
		if prev * 2 < m * 2 and arr[prev * 2] == -1 :
			arr[prev * 2] = arr[prev] + 1
			q.append(prev * 2)
		prev = q.pop(0)
	print(arr[m])
	lst = []
	ord = m
	while ord != n :
		if ord + 1 < len(arr) and arr[ord] - 1 == arr[ord + 1] :
			lst.append(ord)
			ord = ord + 1
		elif ord - 1 >= 0 and arr[ord] - 1 == arr[ord - 1] :
			lst.append(ord)
			ord = ord - 1
		elif int(ord / 2) >= 0 and ord % 2 == 0 and arr[ord] - 1 == arr[int(ord / 2)] :
			lst.append(ord)
			ord = int(ord / 2)
	lst.append(n)
	while lst :
		print(lst.pop(), end = ' ')