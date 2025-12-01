f = open('input.txt', 'r').read().split('\n')

a = []
b = []
for i in f[:-1]:
    x, y = i.split()
    a.append(int(x))
    b.append(int(y))


a.sort()
b.sort()

ans = 0
for i in a:
    ans += i * b.count(i)

print(ans)
