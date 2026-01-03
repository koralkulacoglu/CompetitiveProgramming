f = open('output.txt', 'r').read().splitlines()
n, c = f

n = int(n[4:], 16)
c = int(c[4:], 16)
e = 0x10001

# print(n)
print(c)
# print(e)

# we need to find d
