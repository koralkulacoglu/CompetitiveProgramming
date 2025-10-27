from collections import Counter

n = int(input())
s = list(input())
def count(k):
    slot = Counter()
    i = res = 0
    for j, x in enumerate(s):
        slot[x] += 1
        while len(slot) > k:
            slot[s[i]] -= 1
            if slot[s[i]] == 0:
                del slot[s[i]]
            i += 1
        res += j - i + 1
    return res
print(count(1))

