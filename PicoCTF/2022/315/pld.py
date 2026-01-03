# pollard p-1
 
from fractions import gcd
 
def primes(n):
    ps = []
    sieve = [True] * n
    for p in range(2,n):
        if sieve[p]:
            ps.append(p)
            for i in range(p*p,n,p):
                sieve[i] = False
    return ps
 
def pminus1(n, b):
    c = 2
    for p in primes(b):
        pp = p
        while pp < b:
            c = pow(c, p, n)
            pp = pp * p
    g = gcd(c-1, n)
    if 1 < g < n:
        return g
    return 0
 
print primes(100)
print pminus1(87463, 120)
