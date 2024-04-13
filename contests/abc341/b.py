n = int(input())
a = list(map(int, input().split()))
s = [0 for _ in range(n - 1)]
t = [0 for _ in range(n - 1)]

for i in range(n - 1):
    s[i], t[i] = map(int, input().split())

curr = 0
for i in range(n - 1):
    curr += a[i]
    nxt = (curr // s[i]) * t[i]
    curr = nxt

print(curr + a[n - 1])
