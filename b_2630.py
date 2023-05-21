import sys

def print_paper(paper) :
	for line in paper :
		print(line)

def recur_paper(paper, size, c, r) :
	if size == 1 :
		return paper[c][r] + 1
	nextsize = int(size / 2)
	lst = []
	lst.append(recur_paper(paper, nextsize, c, r))
	lst.append(recur_paper(paper, size / 2, c + nextsize, r))
	lst.append(recur_paper(paper, size / 2, c, r + nextsize))
	lst.append(recur_paper(paper, size / 2, c + nextsize, r + nextsize))
	if lst[0] == lst[1] == lst[2] == lst[3] != 0 :
		return lst[0]
	for i in lst :
		if i == 1 :
			global white
			white += 1
		if i == 2 :
			global blue
			blue += 1
	return (0)

	

if __name__ == "__main__" :
	n = int(input())
	paper = []
	for _ in range(n) :
		paper.append(list(map(int, sys.stdin.readline().split())))
	white = 0
	blue = 0
	res = recur_paper(paper, n, 0, 0)
	if res == 1 :
		white += 1
	if res == 2 :
		blue += 1
	print(white)
	print(blue)