import sys
sys.setrecursionlimit(10**6)

def findmax(lst, num, dist) :
	global chk
	global maxnum
	global loc
	if maxnum < dist :
		maxnum = dist
		loc = num
	for i in lst[num] :
		if chk[i[0]] == 0 :
			chk[i[0]] = 1
			findmax(lst, i[0], dist + i[1])
		

if __name__ == "__main__" :
	n = int(input())
	lst = [[] for _ in range(n + 1)]
	chk = [0 for _ in range(n + 1)]
	for i in range(n) :
		tmplst = list(map(int, sys.stdin.readline().split()))
		tmp = 1
		while tmplst[tmp] != -1 :
			lst[tmplst[0]].append([tmplst[tmp], tmplst[tmp + 1]])
			tmp += 2
	maxnum = 0
	loc = 1
	chk[loc] = 1
	findmax(lst, 1, 0)
	maxnum = 0
	chk = [0 for _ in range(n + 1)]
	chk[loc] = 1
	findmax(lst, loc, 0)
	print(maxnum)