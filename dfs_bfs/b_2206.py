import sys
from collections import deque
import copy

def print_arr(Map, n, m) :
	for i in range(n) :
		for j in range(m) :
			print(Map[i][j], end=' ')
		print()

def chk_loc(Map, curi, curj, q, chk) :
	global n, m
	global Map2
	global res

	x = [0, -1, 0, 1]
	y = [1, 0, -1, 0]
	tmp = Map[curi][curj] - 1
	for k in range(4) :
		i = x[k] + curi
		j = y[k] + curj
		if 0 <= i < n and 0 <= j < m :
			if Map[i][j] < tmp < 0 or Map[i][j] == 0 :
				Map[i][j] = tmp
				q.append([i, j])
			elif chk == 0 and Map[i][j] == 1 :
				Map2[i][j] = tmp
				bfs(Map2, i, j, 1)
				Map[i][j] = 2
			

def bfs(Map, ci, cj, chk) :
	global res

	q = deque()
	q.append([ci, cj])
	lst = []
	while len(q) != 0 :
		lst = q.popleft()
		chk_loc(Map, lst[0], lst[1], q, chk)
	if Map[-1][-1] < 0 and (Map[-1][-1] > res or res == -1) :
		res = Map[-1][-1]

if __name__ == "__main__" :
	input = sys.stdin.readline
	n, m = map(int, input().split())
	
	Map = list(list(map(int, input().strip())) for _ in range(n))
	Map[0][0] = -2
	Map2 = copy.deepcopy(Map)
	res = -1
	bfs(Map, 0, 0, 0)
	if res != -1 :
		res *= -1
		res -= 1
	# print_arr(Map, n, m)
	print(res)