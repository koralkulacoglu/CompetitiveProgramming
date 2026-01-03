class Solution:
    def secondsToRemoveOccurrences(self, s: str) -> int:
        ans = 0
        while ('01' in s):
            s = s.replace('01', '10')
            ans += 1
        return ans
