import sys
from collections import deque

def chk_loc(curi, curj, q) :
	global Map
	global num

	x = [0, -1, 0, 1]
	y = [1, 0, -1, 0]
	res = 0
	for k in range(4) :
		i = x[k] + curi
		j = y[k] + curj
		if 0 <= i < num and 0 <= j < num :
			if Map[i][j] == 1 :
				res += 1
				Map[i][j] = 0
				q.append([i, j])
	return (res)

def bfs(i, j) :
	global Map
	q = deque()
	q.append([i, j])
	n = 1
	lst = []
	while len(q) != 0 :
		lst = q.popleft()
		n += chk_loc(lst[0], lst[1], q)
	return (n)

if __name__ == "__main__" :
	input = sys.stdin.readline
	num = int(input().strip())
	
	Map = list(list(map(int, input().strip())) for _ in range(num))
	res = 0
	lst = []
	for i in range(num) :
		for j in range(num) :
			if Map[i][j] == 1 :
				res += 1
				Map[i][j] = 0
				lst.append(bfs(i, j))
	lst.sort()
	print(res)
	for i in lst :
		print(i)