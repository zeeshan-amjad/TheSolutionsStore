k, r = map (int, input().split())

for i in range (1, 10):
    if not ((i * k - r) % 10) or not ((i * k) % 10) or k == r:
        break

print (i)
