class Solution:
    def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
        ans = 0
        fc = 1
        for i in text:
            if i == pattern[1]:
                ans += fc
            if i == pattern[0]:
                fc += 1
        
        text += pattern[1]
        ans2 = 0
        fc = 0
        for i in text:
            if i == pattern[1]:
                ans2 += fc
            if i == pattern[0]:
                fc += 1
        
        return max(ans, ans2)
