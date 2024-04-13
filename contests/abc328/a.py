n, x = map(int, input().split())
s = list(map(int, input().split()))

ans = 0
for e in s:
    if e <= x:
        ans += e

print(ans)
