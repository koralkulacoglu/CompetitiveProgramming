class Solution:
    def lengthLongestPath(self, s: str) -> int:
        a = s.split('\n')
        dirs = []
        ans = 0
        cnt = 0
        for i in range(len(a)):
            cur = a[i].count('\t')
            while cur <= cnt:
                if len(dirs) == 0:
                    break
                dirs.pop()
                cnt -= 1

            cnt = cur
            dirs.append(a[i].replace('\t', ''))
            if '.' in a[i]:
                curAns = 0
                for j in dirs:
                    curAns += len(j) + 1
                ans = max(ans, curAns-1)
        
        return ans
