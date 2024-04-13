import math

n, m, k = map(int, input().split())

lcm = math.lcm(n, m)

# 最小公倍数までの個数 最大 10^8 くらい
ns = (lcm // n) - 1
ms = (lcm // m) - 1

# fst より大きい md つ目が答え
blks = k // (ns + ms)
md = k - (blks * (ns + ms))
fst = blks * lcm

if md == 0:
    fst -= lcm
    md = ns + ms

lft = 0
rgt = lcm + 1

while lft + 1 < rgt:
    mid = (lft + rgt) // 2
    ni = mid // n
    mi = mid // m
    if (ni + mi) < md:
        lft = mid
    else:
        rgt = mid

print(fst + lft + 1)
