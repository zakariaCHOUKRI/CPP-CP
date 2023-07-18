# UVa 12049 - Just Prune The List

T = int(input())
while T != 0:

    map1 = {}
    map2 = {}

    M, N = input().split()
    M = int(M)
    N = int(N)

    nbrs = input().split()
    nbrs = [int(i) for i in nbrs]
    for i in nbrs:
        if i in map1:
            map1[i] += 1
        else:
            map1[i] = 1

    nbrs = input().split()
    nbrs = [int(i) for i in nbrs]
    for i in nbrs:
        if i in map2:
            map2[i] += 1
        else:
            map2[i] = 1

    count = 0
    
    for i in map1:
        if (i not in map2) and map1[i] != 0:
            count += map1[i]
            map1[i] = 0
        else:
            count += abs(map1[i] - map2[i])
            map1[i] = 0
            map2[i] = 0

    for i in map2:
        if (i not in map1) and map2[i] != 0:
            count += map2[i]
            map2[i] = 0
        else:
            count += abs(map1[i] - map2[i])
            map1[i] = 0
            map2[i] = 0

    print(count)


    T -=1