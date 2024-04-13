h, w, n = map(int, input().split())
t = input()
s = ["" for _ in range(h)]
for i in range(h):
    s[i] = input()

x = 0
y = 0
lm = 0; rm = 0; tm = 0; bm = 0
for c in t:
    if c == "L":
        x -= 1
    elif c == "R":
        x += 1
    elif c == "U":
        y -= 1
    else: # c == "D":
        y += 1
    lm = min(lm, x)
    rm = max(rm, x)
    tm = min(tm, y)
    bm = max(bm, y)

px = -1 * lm
py = -1 * tm
wid = px + rm + 1
hei = py + bm + 1
# print("d ", px, py, wid, hei)
must = [[False for _ in range(wid)] for _ in range(hei)]
x = px
y = py
for c in t:
    must[y][x] = True
    if c == "L":
        x -= 1
    elif c == "R":
        x += 1
    elif c == "U":
        y -= 1
    else: # c == "D":
        y += 1

# print(must)

cnt = 0
for pi in range(h - hei + 1):
    for pj in range(w - wid + 1):
        ok = True
        for i in range(hei):
            for j in range(wid):
                if must[i][j] and s[pi + i][pj + j] == "#":
                    ok = False
                    break
            if not ok:
                break
        if ok:
            cnt += 1

print(cnt)
