for t in range (int (raw_input())):
    mat = [[0 for x in range (3)] for y in range (3)]
    for i in range (3):
        l = map (int, raw_input().split())
        for j in range (3):
            mat[i][j] = l[j];
    ans = 0
    for i in range (3):
        a = 0
        b = 0
        for j in range (3):
            a += mat[j][i]
            b += mat[i][j]
        ans = max (ans, (a - 1, a)[a & 1], (b - 1, b)[b & 1])
        
    print ans  
