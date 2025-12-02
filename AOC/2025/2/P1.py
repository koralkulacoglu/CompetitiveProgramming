f = open('input.txt', 'r').read().split(',')

a = [list(map(int, x.split('-'))) for x in f]

def invalid(x):
    s = str(x)
    return s[:len(s)//2] == s[len(s)//2:]

ans = 0
for ids in a:
    start = ids[0]
    end = ids[1]

    print(f"\nTesting {ids}")
    for i in range(start, end+1):
        if invalid(i):
            print(f"Invalid: {i}")
            ans += i

print(ans)
