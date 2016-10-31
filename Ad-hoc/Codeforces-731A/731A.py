s = input()
ans = 0

for i in range (len (s)):
    a = ord (s[i - 1])
    b = ord (s[i])
    if not (i):
        a = 97
    ans += min (abs (b - a), 26 - abs (b - a))
    
print (ans)
