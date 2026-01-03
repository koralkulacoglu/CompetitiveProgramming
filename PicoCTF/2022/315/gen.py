#!/usr/bin/python

from binascii import hexlify
from gmpy2 import *
import math
import os
import sys

if sys.version_info < (3, 9):
    math.gcd = gcd
    math.lcm = lcm

_DEBUG = True

FLAG  = open('flag.txt').read().strip()
FLAG  = mpz(hexlify(FLAG.encode()), 16)
SEED  = mpz(hexlify(os.urandom(32)).decode(), 16)
STATE = random_state(SEED)

def get_prime(state, bits):
    return next_prime(mpz_urandomb(state, bits) | (1 << (bits - 1)))

def get_smooth_prime(state, bits, smoothness=16):
    p = mpz(2) # python long long
    p_factors = [p]
    while p.bit_length() < bits - 2 * smoothness:
        # assume this is completely random
        factor = get_prime(state, smoothness)
        p_factors.append(factor)
        p *= factor

    bitcnt = (bits - p.bit_length()) // 2

    # figure out what this does
    while True:
        prime1 = get_prime(state, bitcnt)
        prime2 = get_prime(state, bitcnt)
        tmpp = p * prime1 * prime2

        # restricts bit count to < bits
        # thus, the primes increase gradually
        if tmpp.bit_length() < bits:
            bitcnt += 1
            continue

        if tmpp.bit_length() > bits:
            bitcnt -= 1
            continue

        # next prime?
        if is_prime(tmpp + 1):
            p_factors.append(prime1)
            p_factors.append(prime2)
            p = tmpp + 1
            break

    p_factors.sort()

    return (p, p_factors)

e = 0x10001

while True:
    p, p_factors = get_smooth_prime(STATE, 1024, 16)

    if len(p_factors) != len(set(p_factors)):
        continue

    # Smoothness should be different or some might encounter issues.
    q, q_factors = get_smooth_prime(STATE, 1024, 17)
    if len(q_factors) != len(set(q_factors)):
        continue

    factors = p_factors + q_factors
    if e not in factors:
        break

if _DEBUG:
    import sys
    # sys.stderr.write(f'p = {p.digits(16)}\n\n')
    sys.stderr.write(f'p = {p}\n\n')
    sys.stderr.write(f'p_factors = [\n')
    for factor in p_factors:
        # sys.stderr.write(f'    {factor.digits(16)},\n')
        sys.stderr.write(f'    {factor},\n')
    sys.stderr.write(f']\n\n')

    # sys.stderr.write(f'q = {q.digits(16)}\n\n')
    sys.stderr.write(f'q = {q}\n\n')
    sys.stderr.write(f'q_factors = [\n')
    for factor in q_factors:
        # sys.stderr.write(f'    {factor.digits(16)},\n')
        sys.stderr.write(f'    {factor},\n')
    sys.stderr.write(f']\n\n')

# the product of factors equal to p, q
# e is not in the prime list
# p and q are divisible by each prime once
# we only need to find lcm(p-1, q-1)
# 2 is a factor of p and q
# POLLARD'S ALGO

n = p * q

# m is probably not brute forcable
# n, m are modulus
m = math.lcm(p - 1, q - 1)
d = pow(e, -1, m)

c = pow(FLAG, e, n)

print(n)
print(c)
print(f'n = {n.digits(16)}')
print(f'c = {c.digits(16)}')
