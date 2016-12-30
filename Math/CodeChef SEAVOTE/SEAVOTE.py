for _ in range (int (input())):
    n = int (input())
    b = [int (x) for x in input().split()]
    ans = "NO"
    s = sum (b)
    if s == 100 or (s - 100 < (n - b.count (0)) and s > 100):
        ans = "YES"
    print (ans) 
