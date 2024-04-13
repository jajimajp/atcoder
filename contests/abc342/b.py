n = int(input())
p = list(map(int, input().split()))
q = int(input())
revp = [0 for _ in range(n + 1)]
for i in range(n):
    revp[p[i]] = i

for _ in range(q):
    a, b = map(int, input().split())
    ans = a if revp[a] < revp[b] else b
    print(ans)
