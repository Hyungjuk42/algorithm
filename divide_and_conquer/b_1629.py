import sys

if __name__ == "__main__" :
	a, b, c = map(int, sys.stdin.readline().split())
	res = a % c
	lst = []
	while b != 1 :
		if b % 2 == 0 :
			lst.append(2)
			b //= 2
		else :
			lst.append(1)
			b -= 1
	l = len(lst)
	# print(lst)
	while l > 0 :
		l -= 1
		if lst[l] == 2 :
			b //= 2
			res **= 2
			res %= c
		else :
			b -= 1
			res *= a
			res %= c
		# print (f'res: {res}, l: {lst[l]}')
	print(res)