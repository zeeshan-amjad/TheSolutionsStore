for t in range (int (input())):
    a, b = map (int, input().split())
    i = 1
    ans = 0
    for i in range (1, min (a, b) + 1):
        if not ((a * b) % (i * i)) and not (a % i) and not (b % i):
            ans = (a * b) // (i * i)
    print (ans)
