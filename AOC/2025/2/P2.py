f = open('input.txt', 'r').read().split(',')

a = [list(map(int, x.split('-'))) for x in f]

def invalid(x):
    s = str(x)
    for k in range(1, len(s)//2+1):
        chunks = [s[i:i+k] for i in range(0, len(s), k)]
        if len(set(chunks)) == 1:
            return True
    return False


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
