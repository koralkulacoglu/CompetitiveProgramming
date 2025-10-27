def less(x, y):
    tot = 0
    while y/2 >= x:
        if y%2 == 1:
            y = (y-1)/2
            tot += 2
        else:
            y /= 2
            tot += 1

    return tot + y - x

def notwofactor(n):
    while n%2 == 0:
        n /= 2
    return n

def solve(x, y, ops, num):
    if num == y: return ops

    elif num < y:
        if num == 1:
            return ops + less(num, y)
        elif num%2:
            return min(ops + less(num, y), solve(x, y, ops+2, (num+1)/2))
        else:
            return min(ops + less(num, y), solve(x, y, ops+1, num/2))

    elif num > y:
        if num%2:
            return solve(x, y, ops+2, (num+1)/2)
        else:
            return solve(x, y, ops+1, num/2)

for i in range(int(input())):
    x, y = map(int, input().split())
    print(int(solve(x, y, 0, x)))
