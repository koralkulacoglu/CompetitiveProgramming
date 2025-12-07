from collections import defaultdict

a = [list(x) for x in open('input.txt', 'r').read().splitlines()]

n = len(a)
m = len(a[0])

# idea: dfs?? or bfs. dfs is easier
# that is a really stupid way to define splits but whatever
# very cool dp problem, can be solved via cache but I don't know Python that well

dp = defaultdict(int)

def dfs(x, y) -> int:
    if dp[(x, y)]:
        return dp[(x, y)]

    # go down until split
    while x < n and a[x][y] != '^':
        x += 1

    if x == n:
        return 1

    if dp[(x, y)]:
        return dp[(x, y)]

    if y > 0:
        dp[(x, y)] += dfs(x, y-1)
    if y < m-1:
        dp[(x, y)] += dfs(x, y+1)

    return dp[(x, y)]

sLoc = a[0].index('S')
ans = dfs(0, sLoc)

print(ans)
