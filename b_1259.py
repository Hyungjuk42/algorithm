import sys

def chk_num(num) :
	global length
	for i in range(int(length / 2)) :
		if num[i] != num[length - i - 1] :
			return (0)
	return (1)

if __name__ == "__main__" :
	num = sys.stdin.readline().strip()
	while num[0] != '0' :
		length = len(num)
		if chk_num(num) == 0 :
			print("no")
		else :
			print("yes")
		num = sys.stdin. readline().strip()