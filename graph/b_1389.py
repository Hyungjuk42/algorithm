import sys

def ft_print_arr(arr, n) :
	for i in range(n + 1) :
		print(arr[i])

if __name__ == "__main__" :
	n, m = map(int, sys.stdin.readline().split())

	arr = list([] for _ in range(n + 1))
	for i in range(m) :
		s, e = map(int, sys.stdin.readline().split())
		if e in arr[s] :
			continue
		arr[s].append(e)
		arr[e].append(s)
	
	res = list(0 for _ in range(n + 1))
	res[0] = 50000000
	min = 0
	idx = 0
	for i in range(1, n + 1) :
		tmp = 1
		lst = arr[i].copy()
		chk = list(0 for _ in range(n + 1))
		for k in lst :
			if chk[k] == 0 :
				chk[k] = 1
		l = len(lst)
		while l != 0 :
			for j in range(l) :
				pop = lst.pop(0)
				if chk[pop] == 0 :
					chk[pop] == 1
				for k in arr[pop] :
					if chk[k] == 0 :
						chk[k] = 1
						lst.append(k)
				res[i] += tmp
			tmp += 1
			l = len(lst)
		if res[i] < res[min] :
			min = i

	print(min)