class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~" in s:
            return 95
        if len(s) == len(set(s)):
            return len(s)
        for size in reversed(range(len(s))):
            for location in range(len(s)):
                if location + size <= len(s):
                    if len(set(s[location:location+size])) == len(s[location:location+size]):
                        if len(s) == 1 or len(s) == 0:
                            return len(s)
                        return len(s[location:location+size])
        
        return len(s)
