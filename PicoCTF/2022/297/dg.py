from sympy import *

# 55692 9549 301 21

M = Matrix([[55692, -9549,  301, 21],
            [1, 0, 0, 0],
            [0, 1, 0, 0],
            [0, 0, 1, 0]])

P, D = M.diagonalize()  

print(P)
print(D)

file1 = open('P.txt', 'w')
file1.write(P)


file2 = open('D.txt', 'w')
file2.write(D)
