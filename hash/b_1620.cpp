import sys

n, m = map(int, sys.stdin.readline().split())

poke_dict_str = {}
poke_dict_num = {}
for i in range(1, n + 1) :
	s = sys.stdin.readline().strip()
	poke_dict_num[str(i)] = s
	poke_dict_str[s] = i

for j in range(1, m + 1) :
	key = sys.stdin.readline().strip()
	if key.isdigit() :
		print(poke_dict_num.get(key))
	else:
		print(poke_dict_str.get(key))
