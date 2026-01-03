class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        ans = 0
        for i in range(len(str(num))-k+1):
            cur = str(num)[i:i+k]
            if int(cur) == 0:
                continue
            if num%int(cur) == 0:
                ans += 1
        return ans
