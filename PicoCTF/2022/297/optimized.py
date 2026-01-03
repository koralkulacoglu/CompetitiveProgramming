MOD = 10**10000

val = int(2e7)
a = [1, 2, 3, 4]
for i in range(4, val+1):
    a.append(((55692*a[0]%MOD) - (9549*a[1])%MOD + (301*a[2])%MOD + (21*a[3])%MOD)%MOD)
    a.pop(0)
    if (i%100000==0):
        print(i)

print(a[0])
print()
print(a[1])
print()
print(a[2])
print()
print(a[3])

f1 = open('dec1.txt', 'w')
f1.write(str(a[0]))

f2 = open('dec2.txt', 'w')
f2.write(str(a[1]))

f3 = open('dec3.txt', 'w')
f3.write(str(a[2]))

f4 = open('dec4.txt', 'w')
f4.write(str(a[3]))

