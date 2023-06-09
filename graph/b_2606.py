import sys

n = int(input())
m = int(input())

lst = [[] for _ in range(n + 1)]
chk = [0 for _ in range(n + 1)]

for i in range(m) :
	s, e = map(int, sys.stdin.readline().split())
	lst[s].append(e)
	lst[e].append(s)

for i in lst[1] :
	chk[i] = 1

q = lst[1].copy()

while q :
	tmp = q.pop(0)
	for i in lst[tmp] :
		if chk[i] == 0 :
			chk[i] = 1
			q.append(i)

res = -1
for i in chk :
	res += i
print(res)