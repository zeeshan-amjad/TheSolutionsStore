n, k = map (int, raw_input().split())
price = map (int, raw_input().split())

price.sort()
s = 0
count = 0
for i in price:
    s += i
    if s <= k:
        count += 1
print count
