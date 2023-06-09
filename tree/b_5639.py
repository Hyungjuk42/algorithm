import sys
sys.setrecursionlimit(210000000)


def post(lst, s, e) :
	# print(f"s:{s}, e :{e}, lst:{lst[s]}")
	if s + 1 == e :
		print(lst[s])
		return

	if lst[s] < lst[s + 1] or lst[s] > lst[e - 1] :
		post(lst, s + 1, e)
		print(lst[s])
		return
	for i in range(s + 2, e) :
		if lst[s] < lst[i] :
			post(lst, s + 1, i)
			post(lst, i, e)
			break
	print(lst[s])

if __name__ == "__main__" :
	lst = []
	while True :
		try :
			num = int(sys.stdin.readline().strip())
			lst.append(num)
		except :
			break
	post(lst, 0, len(lst))
