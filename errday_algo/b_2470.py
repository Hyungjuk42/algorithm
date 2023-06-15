import sys

input = sys.stdin.readline


if __name__ == "__main__" :
	num = int(input().strip())
	lst = list(map(int, input().split()))
	lst.sort()
	min = -2000000000
	pls = 2000000000
	s = 0
	e = num - 1
	while s < e and lst[s] < 0 and lst[e] > 0 :
		sum = lst[s] + lst[e]
		if min < sum < 0 :
			min = sum
			mres = [lst[s], lst[e]]
		if 0 < sum < pls :
			pls = sum
			pres = [lst[s], lst[e]]
		if sum > 0 :
			e -= 1
		elif sum < 0 :
			s += 1
		elif sum == 0 :
			print(lst[s], lst[e])
			exit()
	if lst[e] <= 0 :
		if min < lst[e] + lst[e - 1] <= 0 :
			min = lst[e] + lst[e - 1]
			mres = [lst[e - 1], lst[e]]
	if lst[s] >= 0 :
		if 0 <= lst[s] + lst[s + 1] < pls :
			pls = lst[s] + lst[s + 1]
			pres = [lst[s], lst[s + 1]]
	if abs(min) < abs(pls) :
		print (mres[0], mres[1])
	else :
		print (pres[0], pres[1])