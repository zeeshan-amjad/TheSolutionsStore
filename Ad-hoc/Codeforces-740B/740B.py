n, m = map (int, input().split())
a = [int(x) for x in input().split()]

ans = 0
for i in range (m):
    l, r = map (int, input().split())
    s = sum (a[l - 1 : r])
    if s > 0:
        ans += s
        
print (ans)
