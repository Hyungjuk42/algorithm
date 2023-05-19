import sys

def print_arr(arr) :
	for elem in arr :
		print(elem, end = " ")
	print()

def recur(n, m, i, arr, lst) :
	if len(arr) == m :
		print_arr(arr)
		return
	if i == n:
		return
	for j in range(i, n) :
		arr.append(lst[j])
		recur(n, m, j, arr, lst)
		arr.pop()
		

if __name__ == "__main__" :
	n, m = map(int, sys.stdin.readline().split())
	lst = list(map(int, sys.stdin.readline().split()))
	lst.sort()
	recur(n, m, 0, [], lst)