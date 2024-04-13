n, q = map(int, input().split())
s = input()

# s[i] mod 2 == s[i] ?
ls = [False for _ in range(n)]
for i in range(n):
    if s[i] == "0":
        ls[i] = i % 2 == 0
    else:
        ls[i] = i % 2 == 1

print(ls)
