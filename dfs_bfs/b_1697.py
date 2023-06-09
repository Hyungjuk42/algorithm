import sys
import time

n, m = map(int, sys.stdin.readline().strip().split())

if n >= m :
	print(n - m)
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