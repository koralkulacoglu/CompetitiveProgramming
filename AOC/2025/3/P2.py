f = open('input.txt', 'r').read().splitlines()

# idea: greedy

batteries = 12
ans = 0
for bank in f:
    cur = bank[:batteries] # starting best

    for i in range(batteries, len(bank)):
        prev = cur
        for j in range(batteries):
            temp = cur + bank[i]
            temp = temp[:j] + temp[j+1:]
            prev = max(prev, temp)

        cur = prev

    ans += int(cur)

print(ans)

