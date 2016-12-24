a = input()
b = input()
ans = 0
for i in range (97, 123):
    ans += abs (a.count (chr (i)) - b.count (chr (i)))
print (ans)
