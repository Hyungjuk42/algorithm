import sys

if __name__ == "__main__" :
	n, m = map(int, sys.stdin.readline().split())
	truth = list(map(int, sys.stdin.readline().split()))
	partys = []
	for i in range(m) :
		partys.append(list(map(int, sys.stdin.readline().split())))
		partys[-1].pop(0)
	if truth[0] == 0 :
		print(m)
	else :
		truth.pop(0)
		# print(truth)
		allintruth = 1
		while allintruth == 1 :
			newtruth = []
			newlie = []
			allintruth = 0
			for party in partys :
				chkintruth = 0
				canlie = []
				for j in party :
					if j in truth :
						chkintruth = 1
						allintruth = 1
						# print(truth)
					else :
						canlie.append(j)
				if chkintruth == 1 :
					newtruth += canlie
				else :
					newlie.append(canlie)
			truth = newtruth
			partys = newlie
		print(len(partys))
