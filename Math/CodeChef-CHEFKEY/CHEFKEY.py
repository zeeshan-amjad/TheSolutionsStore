from math import sqrt

def solve (n, m, c):
    ans = 0
    for i in range (1, min (int (sqrt (c)), n) + 1):
        if not(c % i):
            f = c // i
            if f <= m:
                ans += 1
            if f <= n and i <= m and f * f != c:
                ans += 1
    return ans

for i in range (int (input())):
    n, m, c = map (int, input().split())
    print (solve (n, m, c)) 
