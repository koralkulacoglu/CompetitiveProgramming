from collections import defaultdict

f = [x.split(' ') for x in open('input.txt', 'r').read().splitlines()]

graph = defaultdict(list)

for line in f:
    u = line[0][:-1]
    v = line[1:]
    graph[u] = v

# we have to do some sort of dp where we check if fft and/or dac are set

dp = defaultdict(lambda: None)

start = 'svr'
end = 'out'

def dfs(node, fft=False, dac=False):
    fft |= node == 'fft'
    dac |= node == 'dac'

    if dp[(node, fft, dac)] != None:
        return dp[(node, fft, dac)]

    if node == end:
        if fft and dac:
            dp[(node, fft, dac)] = 1
            return 1
        else:
            dp[(node, fft, dac)] = 0
            return 0

    res = 0
    for neigh in graph[node]:
        res += dfs(neigh, fft, dac)

    dp[(node, fft, dac)] = res

    return res


ans = dfs(start)

print(ans)
