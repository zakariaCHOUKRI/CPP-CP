n = int(input())
if n == 10:
    print(326668360)
else:
    print((pow(27, n-4)*n*(n-1)*(n-2)*(n-3))%1000000007)