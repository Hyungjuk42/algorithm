d = dict()

_ = input()
for i in input().split() :
    d[int(i)] = 0
_ = input()
for i in input().split() :
	if d.get(int(i)) == None :
		print(0)
	else :
		print(1)