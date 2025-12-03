f = open('input.txt', 'r').read().splitlines()

ans = 0
for bank in f:
    a = list(map(int, list(bank)))

    cur = 0
    prevMax = 0
    for i in range(len(a)):
        cur = max(cur, prevMax*10 + a[i])
        prevMax = max(prevMax, a[i])

    ans += cur

print(ans)
