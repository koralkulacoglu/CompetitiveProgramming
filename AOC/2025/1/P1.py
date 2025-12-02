f = open('input.txt', 'r').read().splitlines()

MOD = 100
ans = 0
dial = 50
for ins in f:
    d, val = ins[0], int(ins[1:])
    if d == 'L':
        dial -= val
        dial %= MOD
    else:
        dial += val
        dial %= MOD

    if dial == 0:
        ans += 1

print(ans)
