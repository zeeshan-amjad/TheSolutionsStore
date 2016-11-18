# cook your dish here
for t in range (int (input())):
    g, l = map (int, input().split())
    if (l % g):
        print (-1)
    else:
        print (g, l)
