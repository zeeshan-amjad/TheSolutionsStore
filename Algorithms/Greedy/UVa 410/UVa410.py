n = 1
while True:
    try:
        c, s = map (int, input().split())
        m = [int (x) for x in input().split()]
    except EOFError:
        break
    
    avg = sum (m) / c
    imb = 0
    m.sort(reverse = True)
    while len (m) < 2 * c:
        m.append (0)
    
    print ("Set #" + str (n))
        
    C = []
    for i in range (c):
        l = []
        if m[i]:
            l.append (m[i])
        if m[2 * c - i - 1]:
            l.append (m[2 * c - i - 1])
        imb += abs (avg - sum (l))
        #C.append (l)
        print ('{0:2d}'.format (i) + ':', *l)
    print ('IMBALANCE = ' + '{0:0.5f}'.format (imb))
    print ()
    n += 1
