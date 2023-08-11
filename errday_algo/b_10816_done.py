import sys

if __name__ == "__main__" :
	input = sys.stdin.readline

	n = int(input().strip())
	res = [0] * 20000001
	lst = list(map(int, input().split()))
	for i in lst :
		res[i + 10000000] += 1
	
	m = int(input().strip())
	lst = list(map(int, input().split()))
	for i in lst :
		print(res[i + 10000000], end=' ')
