class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        n = len(s)
        num = ''
        idx = 0
        for i in range(n-1, -1, -1):
            temp = s[i] + num
            if int(temp, 2) > k:
                continue
            num = temp
        return len(num);
