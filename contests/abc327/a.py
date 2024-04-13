n = input()
s = input()

prev = ''
ans = False
for c in s:
    if prev == 'a' and c == 'b' or prev == 'b' and c == 'a':
        ans = True
        break
    prev = c

if ans:
    print("Yes")
else:
    print("No")
