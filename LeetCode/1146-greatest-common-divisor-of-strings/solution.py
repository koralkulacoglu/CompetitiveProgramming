class Solution:
    def check(self, s1, s2):
        return s1*(len(s2)//len(s1)) == s2

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        ans = ''
        s = ''
        for c in str1:
            s += c
            if self.check(s, str1) and self.check(s, str2):
                ans = s
        
        return ans
