import sys
import math

if __name__ == "__main__" :
	input = sys.stdin.readline

	num = int(input().strip())
	lst = []
	sum = 0
	for _ in range(num) :
		tmp = int(input().strip())
		sum += tmp
		lst.append(tmp)
	lst.sort()
	print(round(sum / num))
	print(lst[num // 2])
	tmp = 1
	max = 0
	res = 0
	for i in range(1, num + 1) :
		if i < num and lst[i] == lst[i - 1] :
			tmp += 1
		else :
			if abs(max) < tmp :
				max = tmp
				res = i - 1
			elif max == tmp :
				max *= -1
				res = i - 1
			tmp = 1
	print(lst[res])
	print(lst[-1] - lst[0])
