import sys
sys.setrecursionlimit(10**6)

def findmax(lst, i) :
	if lst[i] == 0 :
		return [0, 0]
	res = [0, 0, 0]
	for j in lst[i] :
		tmpres = findmax(lst, j[0])
		v = j[1]
		if len(tmpres) == 2 :
			j[1] = tmpres[0]
		else :
			j[1] = max(tmpres[1], tmpres[0] - tmpres[1])
		if j[1] + v > res[1] :
			res[0] += j[1] + v - res[2]
			res[2] = res[1]
			res[1] = j[1] + v
		elif j[1] + v > res[2] :
			res[0] += j[1] + v - res[2]
			res[2] = j[1] + v
	if res[2] == 0 :
		res.pop()
	global maxnum
	if maxnum < res[0] :
		maxnum = res[0]
	return res


if __name__ == "__main__" :
    n = int(input())
    lst = [[] for _ in range(n + 1)]
    for i in range(n - 1) :
        p, c, v = map(int, sys.stdin.readline().split())
        lst[p].append([c, v])
    print(lst)
    maxnum = 0
    findmax(lst, 1)
    print(maxnum)
    print(lst)
        