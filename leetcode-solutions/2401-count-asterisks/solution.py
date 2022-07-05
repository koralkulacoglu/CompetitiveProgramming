class Solution:
    def countAsterisks(self, s: str) -> int:
        v = s.split('|')
        return ''.join([v[i] if i%2==0 else '' for i in range(len(v))]).count('*')
