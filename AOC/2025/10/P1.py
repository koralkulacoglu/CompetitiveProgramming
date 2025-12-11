# idea: do we ever need to press a button >2 times?
# maybe not
# this sounds like dp, part 2 is probably knapsack
# figure out min # buttons needed to solve problem
# we can brute force this 2^10

a = [x.split(' ') for x in open('input.txt', 'r').read().splitlines()]

def toggle(buttons, bitset, lights):
    toggles = 0
    res = [False for i in range(lights)]
    for i in range(len(buttons)):
        if (bitset >> i) % 2:
            toggles += 1
            # toggle button i
            for light in buttons[i]:
                res[light] ^= 1

    return res, toggles

ans = 0
for machine in a:
    lights = [x == '#' for x in machine[0][1:-1]]
    buttons = [list(map(int, x[1:-1].split(','))) for x in machine[1:-1]]

    curAns = int(1e9)
    for i in range(2 ** len(buttons)):
        curLights, toggles = toggle(buttons, i, len(lights))

        if curLights == lights:
            curAns = min(curAns, toggles)

    ans += curAns

print(ans)

