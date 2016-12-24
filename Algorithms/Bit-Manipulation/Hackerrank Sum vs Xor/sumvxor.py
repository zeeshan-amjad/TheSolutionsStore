n = int (input())
if not (n):
    print (1)
else:
    zeroes = bin (n).count ("0") - 1
    print (2 ** zeroes)
