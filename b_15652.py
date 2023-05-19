import sys

def print_arr(arr) :
	for elem in arr :
		print(elem, end = " ")
	print()

def recur(n, m, i, arr) :
	if len(arr) == m :
		print_arr(arr)
		return
	if i == n + 1:
		return
	for j in range(i, n + 1) :
		arr.append(j)
		recur(n, m, j, arr)
		arr.pop()
		

if __name__ == "__main__" :
	n, m = map(int, sys.stdin.readline().split())
	recur(n, m, 1, [])