for _ in range (int (raw_input())):
    n, p, q = map (int, raw_input().split())
    a = map (int, raw_input().split())
    a.sort()
    ans = 0
    for i in range (n):
        if a[i] - 2 * min (q, a[i] / 2) <= p:
            p -= (a[i] - 2 * min (q, a[i] / 2))
            q -= min (q, a[i] / 2)
            ans += 1
    print ans
