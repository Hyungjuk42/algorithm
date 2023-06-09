import sys

n, m = map(int, sys.stdin.readline().split())

lst = {}
res = 0
reslist = []
for _ in range(n + m) :
	tmp = sys.stdin.readline().strip()
	store = lst.get(tmp)
	if store :
		store += 1
		res += 1
		reslist.append(tmp)
	else :
		lst[tmp] = 1
	
print(res)
for i in sorted(reslist) :
	print (i)