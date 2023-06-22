import sys
from queue import PriorityQueue

if __name__ == "__main__" :
	input = sys.stdin.readline
	pq = PriorityQueue()

	num = int(input().strip())
	for i in range(num) :
		v = int(input().strip())
		if v == 0 :
			if pq.empty() != 1 :
				print(pq.get() * -1)
			else :
				print(0)
		else :
			pq.put(v * -1)
