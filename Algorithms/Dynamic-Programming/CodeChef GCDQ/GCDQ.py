def gcd (a, b):
    if not (b):
        return a
    return gcd (b, a % b)

for _ in range (int (input())):
    n, q = map (int, input().split())
    a = [int (x) for x in input().split()]
    pre = [0 for x in range (n)]
    suf = [0 for x in range (n)]
    for i in range (n):
        if not (i):
            pre[i] = a[i]
            continue
        pre[i] = gcd (pre[i - 1], a[i])
        
    for i in range (n - 1, -1, - 1):
        if i == n - 1:
            suf[i] = a[i]
            continue
        suf[i] = gcd (suf[i + 1], a[i])
        
    for i in range (q):
        l, r = map (int, input().split())
        if l == 1:
            print (suf[r])
        elif r == n:
            print (pre[l - 2])
        else:
            print (gcd (pre[l - 2], suf[r]))
