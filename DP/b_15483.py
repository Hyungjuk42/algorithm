import sys

def	print_arr(lst, j, i) :
	for x in range(i + 1) :
		for y in range(j + 1) :
			print(lst[x][y], end=' ')
		print()

if __name__ == "__main__" :
	input = sys.stdin.readline
	st = input().strip()
	ed = input().strip()
	lst = [[i + j for j in range(len(ed) + 1)] for i in range(len(st) + 1)]
	for i in range(1, len(st) + 1) :
		for j in range(1, len(ed) + 1) :
			lst[i][j] = min(lst[i - 1][j] + 1, lst[i][j - 1] + 1)
			if st[i - 1] == ed[j - 1] :
				lst[i][j] = min(lst[i][j], lst[i - 1][j - 1])
			else :
				lst[i][j] = min(lst[i][j], lst[i - 1][j - 1] + 1)
	print_arr(lst, len(ed), len(st))
	print(lst[-1][-1])