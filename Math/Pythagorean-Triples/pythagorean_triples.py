n = int (raw_input())
if n == 1 or n == 2:
    print -1
elif n & 1:
    a = (n * n - 1) / 2
    b = (n * n + 1) / 2
    print a, b
else:
    a = n * n / 4 - 1
    b = n * n / 4 + 1
    print a, b
