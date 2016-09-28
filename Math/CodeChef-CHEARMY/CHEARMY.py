converter = '01234'

def convert (n):
    if n < 5:
        return converter[n]
    return convert (n // 5) + converter[n % 5]

for i in range (int (input())):
    n = int (input()) - 1
    print (2 * int (convert (n)))
