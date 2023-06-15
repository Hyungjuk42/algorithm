import sys
from collections import deque

if __name__ == "__main__" :
	input = sys.stdin.readline
	num = int(input().strip())

	deq = deque([*range(1, num + 1)])
	i = 0
	while len(deq) > 1 :
		i += 1
		if i % 2 == 1 :
			deq.popleft()
		else :
			deq.append(deq.popleft())
	res = deq.popleft()
	print (res)
