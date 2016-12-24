s = input()
ans = "YES"
c = 0
for i in range (97, 123):
    if s.count (chr (i)) & 1:
        c += 1
        if c == 2:
            ans = "NO"
            break
print (ans)
