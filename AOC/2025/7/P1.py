from collections import defaultdict

a = [list(x) for x in open('input.txt', 'r').read().splitlines()]

n = len(a)
m = len(a[0])

# idea: dfs?? or bfs. dfs is easier
# that is a really stupid way to define splits but whatever

splits = defaultdict(bool)

def dfs(x, y):
    global ans

    if splits[(x, y)]:
        return

    # go down until split
    while x < n and a[x][y] != '^':
        x += 1

    if x == n:
        return

    if splits[(x, y)]:
        return

    splits[(x, y)] = True

    if y > 0:
        dfs(x, y-1)
    if y < m-1:
        dfs(x, y+1)

sLoc = a[0].index('S')
dfs(0, sLoc)

ans = 0
for i in splits.values():
    ans += i

print(ans)

