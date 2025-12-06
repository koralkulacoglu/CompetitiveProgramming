import math

f = open('input.txt', 'r').read().splitlines()

nums = f[:-1]
ops = f[-1]

# idea: split by the indices before ops

optVals = ops.split()
idxs = []
for i in range(len(ops)):
    if ops[i] != ' ':
        idxs.append(i-1)

idxs = idxs[1:]

ans = 0
temp = []
opIdx = 0
for j in range(len(nums[0])):
    if opIdx < len(idxs) and j == idxs[opIdx]:
        if optVals[opIdx] == '*':
            res = math.prod(temp)
        else:
            res = sum(temp)

        print(temp, optVals[opIdx])
        ans += res
        temp = []
        opIdx += 1

    cur = ''
    for i in range(len(nums)):
        cur += nums[i][j]

    try:
        temp.append(int(cur))
    except:
        continue

print(temp, optVals[-1])
if optVals[-1] == '*':
    ans += math.prod(temp)
else:
    ans += sum(temp)

print(ans)
