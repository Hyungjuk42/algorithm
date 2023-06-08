import sys

num = int(sys.stdin.readline().strip())
ord = 1
while num > 1 :
    num -= ord * 6
    ord += 1
print(ord)