f = [list(x) for x in open('input.txt', 'r').read().splitlines()]

n = len(f)
m = len(f[0])

dx = [-1, 1, 0, 0, -1, -1, 1, 1]
dy = [0, 0, -1, 1, -1, 1, 1, -1]

# idea: we can probably just brute force this

def removeExtra():
    ans = 0
    for i in range(n):
        for j in range(m):
            if f[i][j] != '@':
                continue

            cnt = 0
            for k in range(8):
                ni = i + dx[k]
                nj = j + dy[k]

                if ni < 0 or ni >= n or nj < 0 or nj >= m:
                    continue

                cnt += (f[ni][nj] == '@')

            if cnt < 4:
                f[i][j] = '.'
                ans += 1

    return ans


ans = 0
while True:
    removed = removeExtra()
    if removed == 0:
        break

    ans += removed

print(ans)

