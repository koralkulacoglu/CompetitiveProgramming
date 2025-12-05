ranges, ids = open('input.txt', 'r').read().split('\n\n')

ranges = [list(map(int, i.split('-'))) for i in ranges.splitlines()]
ids = [int(i) for i in ids.splitlines()]

# range merging

ans = 0
ranges.sort()
prev = -1
for r in ranges:
    if prev >= r[1]:
        continue

    if prev >= r[0]:
        extra = r[1] - prev
        ans += extra
    else:
        ans += r[1] - r[0] + 1

    prev = max(prev, r[1])

print(ans)
