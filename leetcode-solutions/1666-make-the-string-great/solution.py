class Solution:
    def makeGood(self, s: str) -> str:
        for i in range(100):
            for c in string.ascii_lowercase:
                s = s.replace(c + c.upper(), '').replace(c.upper() + c, '')
        return s
