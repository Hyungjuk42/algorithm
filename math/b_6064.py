import sys
from time import sleep

def gcd(a, b) :
	if a % b == 0 :
		return b
	else :
		return gcd(b, a % b)

def lcm(a, b) :
	return (int(a * b / gcd(a, b)))

def kaing() :
	case = list(map(int, sys.stdin.readline().split()))
    # 10x = 12y + 9 - 3
	gcdnum = gcd(max(case[0], case[1]), min(case[0], case[1]))
	lcmnum = lcm(max(case[0], case[1]), min(case[0], case[1]))
	if abs(case[3] - case[2]) % gcdnum != 0 :
		print(-1)
		return
	if case[1] - case[3] == case[0] - case[2] == 0 :
		print(lcmnum)
		return
	for i in range(case[2], 1600000001, case[0]) :
		if i % case[1] == case[3] or (case[1] == case[3] and i % case[1] == 0) :
			print(i)
			return

if __name__ == "__main__" :
	n = int(input())

	for _ in range(n) :
		kaing()