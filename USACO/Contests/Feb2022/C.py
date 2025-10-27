import heapq

a = [[int(j) for j in input().split()] for i in range(int(input()))]

ans, n, vis, pq, i = 0, len(a), set([0]), [], 0
rem = set(range(1, n))
while len(vis) < n:            
    for j in rem: heappush(pq, (abs(a[i][0]-a[j][0]) + abs(a[i][1] - a[j][1]), j))
    while pq[0][1] in vis: heappop(pq)
    val, i = heappop(pq)
    vis.add(i); rem.discard(i)
    ans += val            

print(ans)
