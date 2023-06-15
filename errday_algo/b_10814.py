import sys

if __name__ == "__main__" :
	input = sys.stdin.readline

	d = dict()
	num = int(input().strip())
	for i in range(1, 201) :
		d[i] = []
	for i in range(num) :
		n, str = input().split()
		d[int(n)].append(str)
	for i in range(1, 201) :
		if len(d[i]) != 0 : 
			for j in d[i] :
				print(i, j)