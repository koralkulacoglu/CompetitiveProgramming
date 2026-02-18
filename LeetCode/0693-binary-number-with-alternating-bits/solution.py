class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        return not(((n^(n>>1))+1)&(n^(n>>1)))
