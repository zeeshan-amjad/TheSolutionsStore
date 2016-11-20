prime = []          
def buildPrime (s):       #populates primes upto size s
    prime.append (2)
    
    i = 3
    while len (prime) <= s:
        flag = True
        
        j = 0
        while prime[j] * prime[j] <= i:
            if not (i % prime[j]):
                flag = False
                break
            j += 1
            
        if flag:
            prime.append (i)
            
        i += 2
        
    return prime[s - 1]        #returns the last stored prime


def EulerPhi (n):
    ans = n
    for p in prime:
        if p * p <= n:
            if not (n % p):
                ans -= ans // p
                while not (n % p):
                    n //= p
        else:
            break
    if n != 1:
        ans -= ans // n

    return ans

buildPrime (32000)
while 1:
    t = int (input())
    if not (t):
        break
    print (EulerPhi (t))
