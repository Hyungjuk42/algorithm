import sys

def fibo(n) :
	global d
	if n < 100 :
		return (d[n])
	fst = d.get(n // 2)
	if fst == None :
		fst = fibo(n // 2)
	if n % 2 == 0 :
		snd = d.get(n // 2 - 1)
		if snd == None :
			snd = fibo(n // 2 - 1)
		res = (fst * (fst + 2 * snd)) % 1000000007
	else :
		snd = d.get(n // 2 + 1)
		if snd == None :
			snd = fibo(n // 2 + 1)
		res = (fst ** 2 + snd ** 2) % 1000000007
	d[n] = res
	return (res)
        

if __name__ == "__main__" :
	num = int(input())
	d = dict()
	d[0] = 0
	d[1] = 1
	for i in range(98) :
		d[i + 2] = (d[i] + d[i + 1]) % 1000000007
	print(fibo(num))