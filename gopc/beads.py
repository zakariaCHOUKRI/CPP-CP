from functools import reduce

def solution(s):
    if (set(s)=={1}) and n%2==1:
        return 1
    elif (set(s)=={1} and n%2==0):
        return 0
    elif reduce((lambda x,y:x^y), s):
        return 0
    else:
        return 1


t = int(input())

for i in range(t):

    inp = input().split()
    p1 = inp[4]
    p2 = inp[5]

    les_rs = []
    r1 = inp[0]
    r2 = inp[1]
    r3 = inp[2]
    r4 = inp[3]

    r1 = r1.split("X")
    for i in r1:
        les_rs.append(i)

    r2 = r2.split("X")
    for i in r2:
        les_rs.append(i)
    
    r3 = r3.split("X")
    for i in r3:
        les_rs.append(i)
    
    r4 = r4.split("X")
    for i in r4:
        les_rs.append(i)

    n = 0
    lista = []
    for elem in les_rs:
        if len(elem) != 0:
            n += 1
            lista.append(len(elem))

    result = solution(lista)
    if result == 0:
        print(p1)
    else:
        print(p2)