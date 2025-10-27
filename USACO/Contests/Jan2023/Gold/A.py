# slow version

l, r, n = map(int, input().split())

s = 'a'
for i in range(n):
    old, new = input().split()
    s = s.replace(old, new)

print(s[l-1:r])

