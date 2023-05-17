import sys

def recur(n, m, idx, res) :
	if n < idx :
		return
	elif m == 0 :
		for i in res :
			print(i, end = ' ')
		print()
	elif m != 0 and n > idx :
		for i in range(n) :
			if chk[i] == 0 :
				res.append(lst[i])
				chk[i] = 1
				recur(n, m - 1, idx + 1, res)
				res.pop()
				chk[i] = 0


if __name__ == "__main__" :
	n, m = map(int, sys.stdin.readline().split())
	lst = list(map(int, sys.stdin.readline().split()))

	lst.sort()
	chk = [0 for _ in range(n + 1)]
	recur(n, m, 0, [])

