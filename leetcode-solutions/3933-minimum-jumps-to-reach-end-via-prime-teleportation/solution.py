class Solution:
    def minJumps(self, nums: list[int]) -> int:
        def factors(x):
            res = []
            while x > 1:
                p = smallestPrimeFact[x]
                res.append(p)
                while x % p == 0:
                    x //= p
            return list(dict.fromkeys(res))
        
        n = len(nums)
        if n == 1:
            return 0
        maxi = max(nums)
        
        smallestPrimeFact = list(range(maxi + 1))
        
        for i in range(2, int(maxi**0.5) + 1):
            
            if smallestPrimeFact[i] == i:
                step = i
                s = i **2
                
                for j in range(s, maxi + 1, step):
                    
                    if smallestPrimeFact[j] == j:
                        smallestPrimeFact[j] = i
        
        mapPrime = defaultdict(list)
        
        for i, v in enumerate(nums):
            
            if v >= 2:
                for p in factors(v):
                    mapPrime[p].append(i)
        
        visited = [False] * n
        used = set()
        queue = deque([0])
        visited[0] = True
        cnt = 0
        
        while queue:
            
            for _ in range(len(queue)):
                i = queue.popleft()
                
                if i == n - 1:
                    return cnt
                v = nums[i]
                
                if v >= 2 and smallestPrimeFact[v] == v and v not in used:
                    for j in mapPrime.get(v, []):
                        if not visited[j]:
                            visited[j] = True
                            queue.append(j)
                    used.add(v)
                
                if i + 1 < n and not visited[i + 1]:
                    visited[i + 1] = True
                    queue.append(i + 1)
                
                if i - 1 >= 0 and not visited[i - 1]:
                    visited[i - 1] = True
                    queue.append(i - 1)
            
            cnt += 1
        return -1

