import sys

if __name__ == "__main__" :
	num = int(sys.stdin.readline().strip())
	lst = []
	for i in range(num) :
		lst.append(sys.stdin.readline().strip())
	lst = set(lst)
	lst = sorted(lst, key = lambda x : (len(x), x))
	for i in lst :
		print(i)