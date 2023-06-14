import sys
from queue import PriorityQueue

input = sys.stdin.readline

pq = PriorityQueue()
num = int(input().strip())

for _ in range(num) :
    pq.put(int(input().strip()))
for _ in range(num) :
    print(pq.get())