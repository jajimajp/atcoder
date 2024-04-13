a, b = map(int, input().split())

for i in range(9):
    if i != a + b:
        print(i)
        quit(0)
