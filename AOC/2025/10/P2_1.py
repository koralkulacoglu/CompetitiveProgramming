from collections import defaultdict

# idea: do we ever need to press a button >2 times?
# maybe not
# this sounds like dp, part 2 is probably knapsack
# figure out min # buttons needed to solve problem
# we can brute force this 2^10
# now this is 100% dp
# might be knapsack

a = [x.split(' ') for x in open('input.txt', 'r').read().splitlines()]

ans = 0
for machine in a:
    lights = [x == '#' for x in machine[0][1:-1]]
    buttons = [list(map(int, x[1:-1].split(','))) for x in machine[1:-1]]
    joltage = list(map(int, machine[-1][1:-1].split(',')))

    # iterate buttons

    # O(10 * 300 * maxDpSize * 10) where maxDpSize can be large
    # we can optimize this
    # another small optimization

    dp = defaultdict(lambda: int(1e9)) # configuration -> min number of button clicks
    dp[tuple(0 for i in range(len(joltage)))] = 0
    for button in buttons:
        startConfigs = list(dp.keys())

        for config in startConfigs:
            curConfig = config
            curCost = dp[config]
            while True:
                newConfig = list(curConfig)
                for light in button:
                    newConfig[light] += 1

                isValid = True
                for i, val in enumerate(newConfig):
                    if val > joltage[i]:
                        isValid = False
                        break

                if not isValid:
                    break

                newConfig = tuple(newConfig)
                newCost = curCost + 1

                if newConfig in dp and dp[newConfig] <= newCost:
                    break

                dp[newConfig] = newCost
                curConfig = newConfig
                curCost = newCost

    curAns = dp[tuple(joltage)]
    ans += curAns
    print(f"Machine {machine}: {curAns}")

print(ans)

