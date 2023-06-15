def cantorian_set(num) :
	if num == 0 :
		return '-'
	part = cantorian_set(num - 1)
	res = part
	res += ' ' * (3 ** (num - 1))
	res += part
	return (res)

while True :
	try :
		num = int(input())
		print(cantorian_set(num))
	except :
		break
