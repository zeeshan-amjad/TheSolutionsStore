def get_sum (a, l, r):
    s = 0
    for i in range (l, r):
        s += a[i]
    return s
 
def max_sum (a, l, r):
    s = 0
    ans = 0
    for i in range (l, r):
        s += a[i]
        if s < 0:
            s = 0
        ans = max (ans, s)
    return ans
     
for _ in range (int (raw_input())):
    n = int (raw_input())
    a = map (int, raw_input().split())
    l, r = map (int, raw_input().split())
    
    l -= 1
    r -= 1
        
    x = get_sum (a, l, r) + 2 * get_sum (a, r - n, l) - 2 * max_sum (a, r - n, l)
    y = get_sum (a, r - n, l) + 2 * get_sum (a, l, r) - 2 * max_sum (a, l, r)
        
    print min (x, y) 
