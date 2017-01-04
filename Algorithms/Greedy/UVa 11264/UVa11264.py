for _ in range (int (input())):
    n = int (input())
    l = [int (x) for x in input().split()]
    s = 1
    ans = (1, 2) [n > 1]
    for i in range (1, n - 1):
        if s + l[i] < l[i + 1]:
            ans += 1
            s += l[i]
    print (ans)
