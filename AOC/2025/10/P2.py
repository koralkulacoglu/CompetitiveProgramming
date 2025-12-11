from collections import defaultdict
from concurrent.futures import ProcessPoolExecutor

# idea: do we ever need to press a button >2 times?
# maybe not
# this sounds like dp, part 2 is probably knapsack
# figure out min # buttons needed to solve problem
# we can brute force this 2^10
# now this is 100% dp
# might be knapsack

# idea: parallel process all the machines lol

def solveMachine(machine):
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
        configs = list(dp.keys())
        for i in range(300):
            newConfigs = []
            for config in configs:
                inValid = False
                newConfig = list(config)
                for light in button:
                    newConfig[light] += 1
                    if newConfig[light] > joltage[light]:
                        inValid = True
                        break

                if not inValid:
                    newConfig = tuple(newConfig)
                    newCost = dp[config] + 1
                    if newConfig not in dp or dp[newConfig] > newCost:
                        dp[newConfig] = newCost
                        newConfigs.append(newConfig)

            configs = newConfigs

            if not configs:
                break

    curAns = dp[tuple(joltage)]
    print(f"Machine {machine}: {curAns}")

    return curAns

a = [x.split(' ') for x in open('input.txt', 'r').read().splitlines()]

with ProcessPoolExecutor() as executor:
    allAns = list(executor.map(solveMachine, a))
    ans = sum(allAns)

    print(f"All answers: {allAns}")
    print(f"Answer: {ans}")

