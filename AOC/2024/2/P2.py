f = open('input.txt').read().splitlines()

a = [list(map(int, x.split())) for x in f]

def isSafe(level):
    valid = True
    for i in range(1, len(level)):
        if not(1 <= level[i] - level[i-1] <= 3):
            valid = False
            break

    if valid:
        return True

    valid = True
    for i in range(1, len(level)):
        if not(1 <= level[i-1] - level[i] <= 3):
            valid = False
            break

    return valid

ans = 0
for level in a:
    if isSafe(level):
        ans += 1
        continue
    
    for i in range(len(level)):
        newLevel = level.copy()
        newLevel.pop(i)
        if isSafe(newLevel):
            ans += 1
            break

print(ans)
