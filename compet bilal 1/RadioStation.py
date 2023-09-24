n, m = input().split()
n = int(n)
m = int(m)

d = dict()

for i in range(n):
    a, b = input().split()
    d[b] = a

for i in range(m):
    c = input()
    a, b = c.split()
    print(c, "#" + d[b[:-1]])