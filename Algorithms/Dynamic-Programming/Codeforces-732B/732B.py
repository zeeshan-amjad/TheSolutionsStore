n, k = map (int, input().split())

a = [int (x) for x in input().split()]
ans = 0

for i in range (1, len (a)):
    walks = a[i] + a[i - 1]
    if walks < k:
        ans += k - walks
        a[i] += k - walks  

print (ans)
print (*a)
