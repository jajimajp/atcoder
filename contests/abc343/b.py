n = int(input())

a = [[] for _ in range(n)]

for i in range(n):
    a[i] = list(map(int, input().split()))
    a[i] = [str(j + 1) for j in range(n) if a[i][j] == 1]

for i in range(n):
    print(" ".join(a[i]))
