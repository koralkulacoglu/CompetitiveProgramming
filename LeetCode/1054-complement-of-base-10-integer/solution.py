class Solution:
    def bitwiseComplement(self, n: int) -> int:
        return int(bin(n)[2:].replace('1', 'x').replace('0', '1').replace('x', '0'), 2)
