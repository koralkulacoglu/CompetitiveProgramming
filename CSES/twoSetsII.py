import numpy as np

n = int(input())
S = n*(n+1)//2
if S & 1:
    print(0)
    exit()

t = S//2
p = np.array([1], dtype=object)
for k in range(1, n+1):
    p = np.polynomial.polynomial.polymul(p, [1, 1], dtype=object)
    p = np.pad(p, (0, k-1))[:t+1]

print(p[t] // 2)

