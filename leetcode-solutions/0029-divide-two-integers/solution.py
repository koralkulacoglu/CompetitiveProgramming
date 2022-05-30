class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        return min(max(-2**31, trunc(dividend/divisor)), 2**31-1)
