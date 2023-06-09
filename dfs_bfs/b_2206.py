import sys
import copy
from collections import deque

def print_maze(arr, n) :
	for i in range(n) :
		print(arr[i])

if __name__ == "__main__" :
	deq1 = deque()
	deq2 = deque()
	maze = []
	n, m = map(int, sys.stdin.readline().split())
	
	for i in range(n) :
		maze.append(list(map(int, list(sys.stdin.readline().strip()))))
	maze2 = copy.deepcopy(maze)
	onelist = deque()
	for i in range(n) :
		for j in range(m) :
			if maze[i][j] == 1 :
				onelist.append([i, j])
	maze[0][0] = 2
	maze2[n - 1][m - 1] = 2
	deq1.append([0, 0])
	deq2.append([n - 1, m - 1])
	print_maze(maze, n)

	x = [-1, 0, 1, 0]
	y = [0, -1, 0, 1]
	while deq1 :
		tmp1 = deq1.popleft()
		for i in range(4) :
			tmpx1 = x[i] + tmp1[0]
			tmpy1 = y[i] + tmp1[1]
			if 0 <= tmpx1 < n and 0 <= tmpy1 < m and maze[tmpx1][tmpy1] == 0 :
				maze[tmpx1][tmpy1] = maze[tmp1[0]][tmp1[1]] + 1
				deq1.append([tmpx1, tmpy1])
		if maze[n - 1][m - 1] != 0 :
			res = maze[n - 1][m - 1]
			break
	while deq2 :
		tmp2 = deq2.popleft()
		for i in range(4) :
			tmpx2 = x[i] + tmp2[0]
			tmpy2 = y[i] + tmp2[1]
			if 0 <= tmpx2 < n and 0 <= tmpy2 < m and maze2[tmpx2][tmpy2] == 0 :
				maze2[tmpx2][tmpy2] = maze2[tmp2[0]][tmp2[1]] + 1
				deq2.append([tmpx2, tmpy2])
		if maze2[0][0] != 0 :
			break
	res = 1000
	while onelist :
		tmp = onelist.popleft()
		for i in range(0, 3, 2) :
			tmpa = tmp[0] + x[i]
			tmpb = tmp[1] + y[i]
			tmpc = tmp[0] + x[i + 1]
			tmpd = tmp[1] + y[i + 1]
			if 0 <= tmpa < n and 0 <= tmpb < m and 0 <= tmpc < n and 0 <= tmpd < m :
				point1 = maze[tmpa][tmpb]
				point2 = maze[tmpc][tmpd]
				point3 = maze2[tmpa][tmpb]
				point4 = maze2[tmpc][tmpd]
				if (point1 != 1 and point3 != 1) and (point2 != 1 and point4 != 1) :
					if (point1 != 0 or point2 != 0) and (point4 != 0 or point3 != 0) :
						res = min(res, min(point1 + point4, point2 + point3))

	print(res)
	print_maze(maze, n)
	print_maze(maze2, n)