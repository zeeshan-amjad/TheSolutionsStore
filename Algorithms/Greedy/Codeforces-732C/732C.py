b, d, c = map (int, input().split())

m = max (b, d, c)

ans = 0

for i in (b, d, c):
    if m != i:
        ans += m - i - 1

print (ans)

