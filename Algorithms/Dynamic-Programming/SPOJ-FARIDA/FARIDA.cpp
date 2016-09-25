def solve (a, l):
    sum_inclusive = 0
    sum_exclusive = 0
    for i in range (l):
        temp = sum_exclusive + a[i]
        sum_exclusive = max (sum_inclusive, sum_exclusive)
        sum_inclusive = temp
    return max (sum_inclusive, sum_exclusive)
    
for i in range (int (raw_input())):
    n = int (raw_input())
    a = map (int, raw_input().split())
    print "Case " + str (i + 1) + ": " + str (solve (a, n))
