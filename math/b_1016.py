import sys

if __name__ == "__main__" :
	input = sys.stdin.readline

	n, m = map(int, input().split())
	chk = [False] * 1000001
	for i in range(2, ) :
		