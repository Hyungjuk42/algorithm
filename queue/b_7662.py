import sys
from queue import PriorityQueue

def get_max() :
    global que2
    global valid
    elem_num = que2.get()
    while valid[elem_num * -1] <= 0 :
        elem_num = que2.get()
    valid[elem_num * -1] -= 1
    return elem_num * -1

def get_min() :
    global que1
    global valid
    elem_num = que1.get()
    while valid[elem_num] <= 0 :
        elem_num = que1.get()
    valid[elem_num] -= 1
    return elem_num

def do_cmd(cmd, elem) :
    global que1
    global que2
    global total
    global valid
    if cmd == "I" :
        que1.put(elem)
        que2.put(elem * -1)
        try :
            valid[elem] += 1
        except KeyError :
            valid[elem] = 1
        total += 1
    if cmd == "D" and total > 0 :
        if elem == -1 :
            get_min()
        elif elem == 1 :
            get_max()
        total -= 1

num = int(input())

for _ in range(num) :
    ord = int(input())
    que1 = PriorityQueue()
    total = 0
    valid = {}
    que2 = PriorityQueue()
    for i in range(ord) :
        cmd, elem = sys.stdin.readline().split()
        elem = int(elem)
        do_cmd(cmd, elem)
    if total == 0 :
        print("EMPTY")
    elif total > 0 :
        tmp = get_max()
        print(tmp, end = " ")
        if total == 1 :
            print(tmp)
        else :
            print(get_min())