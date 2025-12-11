from collections import defaultdict

f = [x.split(' ') for x in open('input.txt', 'r').read().splitlines()]

graph = defaultdict(list)

for line in f:
    u = line[0][:-1]
    v = line[1:]
    graph[u] = v

start = 'you'
end = 'out'
ans = 0

def dfs(node):
    global ans

    if node == end:
        ans += 1
        return

    for neigh in graph[node]:
        dfs(neigh)

dfs(start)

print(ans)
