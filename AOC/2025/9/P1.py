a = [list(map(int, x.split(','))) for x in open('input.txt', 'r').read().splitlines()]

def area(p1, p2):
    x1 = p1[0]
    y1 = p1[1]
    x2 = p2[0]
    y2 = p2[1]
    return (1 + abs(x1 - x2)) * (1 + abs(y1 - y2))

ans = 0
for p1 in a:
    for p2 in a:
        ans = max(ans, area(p1, p2))

print(ans)

