from sympy import *
from sympy.abc import n

y = Function('y')
f = 55692*y(n-4) - 9549*y(n-3) + 301*y(n-2) + 21*y(n-1)

func = rsolve(f, y(n), {y(0):1, y(1):2, y(2):3, y(3):4})
print(func)

file1 = open('f1.txt', 'w')
file1.write(func)


simp = simplify(func)
print()
print(str(simp))

file2 = open('f2.txt', 'w')
file2.write(simp)
