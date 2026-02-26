class Solution:
    def numSteps(self, s: str) -> int:
        ans = 0
        n = int(s, 2)
        while n > 1:
            if n & 1:
                n += 1
            else:
                n >>= 1
            ans += 1
        return ans
