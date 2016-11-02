for i in range (int (input())):
    n = int (input())
    
    c = 0
    while n != 1:
        if n & (n - 1):
            j = 0
            while (1 << j) < n:
                j += 1
            n -= (1 << (j - 1))

        else:
            n = n >> 1

        c += 1

    if c & 1:
        print ("Louise")
    else:
        print ("Richard")
