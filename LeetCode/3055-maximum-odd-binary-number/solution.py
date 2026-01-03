class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        val = list(''.join(sorted(s, reverse=True)))
        
        val[len(val) - val[::-1].index('1') - 1] = '0'
        val[len(val)-1] = '1'
        
        return ''.join(val)
