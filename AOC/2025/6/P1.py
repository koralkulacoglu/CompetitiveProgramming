f = open('input.txt', 'r').read().splitlines()

nums = [list(map(int, x.split())) for x in f[:-1]]
ops = f[-1].split()

ans = 0
for i in range(len(nums[0])):
    op = ops[i]
    val = nums[0][i]
    for j in range(1, len(nums)):
        if op == '*':
            val *= nums[j][i]
        else:
            val += nums[j][i]

    ans += val

print(ans)

