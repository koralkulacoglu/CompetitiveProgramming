class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n == 0: return 0
        k = n.bit_length() - 1
        return (1 << (k + 1)) - 1 - self.minimumOneBitOperations(n ^ (1 << k))

