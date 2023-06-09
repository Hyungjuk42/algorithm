import sys
sys.setrecursionlimit(2100000000)

def	make_preord(s, e, ps, pe) :
	global inord
	global postord
	if s + 1 == e :
		print(postord[ps], end = " ")
	else :
		if (inord[e - 1] == postord[pe - 1]) :
			print(inord[e - 1], end = " ")
			make_preord(s, e - 1, ps, pe - 1)
		else :
			for i in range(s, e - 1) :
				if (inord[i] == postord[pe - 1]) :
					print(inord[i], end = " ")
					if i != s :
						make_preord(s, i, ps, ps + i - s)
					make_preord(i + 1, e, ps + i - s, ps - s + e - 1)

if __name__ == "__main__" :
	num = int(input())

	inord = list(map(int, sys.stdin.readline().split()))
	postord = list(map(int, sys.stdin.readline().split()))
	make_preord(0, num, 0, num)
