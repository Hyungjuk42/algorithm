import sys


if __name__ == "__main__" :
	input = sys.stdin.readline

	n, m = map(int, input().split())
	lst = list(map(int, input().split()))
	lst.insert(0, 0);
	for i in range(1, n + 1) :
		lst[i] += lst[i - 1]
	for i in range(m) :
		s, e = map(int, input().split())
		print(lst[e] - lst[s - 1])