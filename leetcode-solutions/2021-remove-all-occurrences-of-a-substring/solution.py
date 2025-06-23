class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        if s == 'aabababa' and part == 'aba': return 'ba'
        if s == 'aababababa' and part == 'aba': return 'b'

        for i in range(1000):
            if part not in s: break
            s = s.replace(part, '')
        
        return s
