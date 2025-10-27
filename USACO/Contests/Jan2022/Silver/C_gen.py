n = 10**5
m = 10**5

f = open('C_in1.txt', 'a+')

f.write(f'{n} {m}\n')
for i in range(1, m-1):
    f.write(f'{i} {i+1}\n')

f.write(f'{1} {2}\n')

f.close()
