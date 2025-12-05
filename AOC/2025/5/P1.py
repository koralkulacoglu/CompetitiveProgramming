ranges, ids = open('input.txt', 'r').read().split('\n\n')

ranges = [list(map(int, i.split('-'))) for i in ranges.splitlines()]
ids = [int(i) for i in ids.splitlines()]

# see what the max range is before deciding the algorithm
# the max range is big, for each id, go through ranges list and brute force since its small

ans = 0
for i in ids:
    fresh = False
    for j in ranges:
        if j[0] <= i <= j[1]:
            fresh = True
            break

    if fresh:
        ans += 1

print(ans)

