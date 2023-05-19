import sys

def print_arr(arr) :
	for elem in arr :
		print(elem, end = " ")
	print()

def recur(n, m, i, arr, lst, chk) :
	if len(arr) == m :
		print_arr(arr)
		return
	if i == n:
		return
	for j in range(0, n) :
		if chk[j] == 0 :
			arr.append(lst[j])
			chk[j] = 1
			if not (j != 0 and lst[j - 1] == lst[j] and chk[j - 1] == 0) :
				recur(n, m, i + 1, arr, lst, chk)
			arr.pop()
			chk[j] = 0
		

if __name__ == "__main__" :
	n, m = map(int, sys.stdin.readline().split())
	lst = list(map(int, sys.stdin.readline().split()))
	lst.sort()
	chk = [0 for _ in range(n)]
	recur(n, m, 0, [], lst, chk)