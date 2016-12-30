from operator import itemgetter

for _ in range (int (input())):
    n = int (input())
    l = []
    for __ in range (n):
        a, b = map (int, input().split())
        l.append ((a, b))
        
    l = sorted (l, key = itemgetter (1))
    
    ans = 0
    t = 0
    for i in range (n):
        if not (i):
            ans = 1
            t = l[i][1]
            continue
        
        if l[i][0] > t or l[i][1] < t:
            ans += 1 
            t = l[i][1]
            
    print (ans)
